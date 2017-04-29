#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define FILE_NOT_FOUND 0
#define FILE_EXISTS 1

int errno = 3;

char input[51];

int main(int argc, char const *argv[]) {
        int server, client;
        uint32_t value = 33, inet_len;
        struct sockaddr_in saddr, caddr;

        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(2223);
        saddr.sin_addr.s_addr = htonl(INADDR_ANY);

        server = socket(PF_INET, SOCK_STREAM, 0);
        if (server == -1) {
                printf("Socket creation error\n");
                return(-1);
        }

        if (bind(server, (struct sockaddr *)&saddr, sizeof(struct sockaddr)) == -1) {
                printf("Socket bind error\n");
                return(-1);
        }

        if (listen(server,5) == -1) {
                printf("Socket listen error\n");
                return(-1);
        }

        while (1) {
                inet_len = sizeof(caddr);
                if ((client = accept(server, (struct sockaddr *)&caddr, &inet_len)) == -1) {
                        printf("Client accept error\n");
                        close(server);
                        return(-1);
                }
                printf("server new client connection [%s/%d]\n", inet_ntoa(caddr.sin_addr), caddr.sin_port);

                read(client, &input, 50);
                printf("received a value of [%s]\n", input);

                // check if file exists
                // @SEE http://stackoverflow.com/a/230068
                value = ntohl(access(input, F_OK) != -1);

                if (write(client, &value, sizeof(value)) != sizeof(value)) {
                        printf("Client accept error\n");
                        close(server);
                        return(-1);
                }
                printf("sent a value of [%d]\n", value);

                if (htonl(value) == FILE_EXISTS) {
                    FILE *file = fopen(input, "r+");
                    while (fgets(input, 50, file) != NULL) {
                        printf("read [%s]\n", input);
                        write(client, &input, 50);
                    }
                    strcpy(input, "cmsc257");
                    write(client, &input, 50);
                }

                close(client);
        }
}
