#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int errno = 3;

int main(int argc, char const *argv[]) {
        int server, client;
        uint32_t value = 33, inet_len;
        struct sockaddr_in saddr, caddr;

        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(16453);
        saddr.sin_addr.s_addr = htonl(INADDR_ANY);

        server = socket(PF_INET, SOCK_STREAM, 0);
        if (server == -1) {
                printf("Socket creation error [%s]\n", strerror(errno));
                return(-1);
        }

        if (bind(server, (struct sockaddr *)&saddr, sizeof(struct sockaddr)) == -1) {
                printf("Socket bind error [%s]\n", strerror(errno));
                return(-1);
        }

        if (listen(server,5) == -1) {
                printf("Socket listen error [%s]\n", strerror(errno));
                return(-1);
        }

        while (1) {
                inet_len = sizeof(caddr);
                if ((client = accept(server, (struct sockaddr *)&caddr, &inet_len)) == -1) {
                        printf("Client accept error [%s]\n", strerror(errno));
                        close(server);
                        return(-1);
                }
                printf("server new client connection [%s/%d]", inet_ntoa(caddr.sin_addr), caddr.sin_port);

                if (read(client, &value, sizeof(value) != sizeof(value))) {
                        printf("Network data writing error [%s]\n", strerror(errno));
                        close(server);
                        return(-1);
                }
                printf("received a value of [%d]\n", value);
                value = ntohl(value);
                printf("which is [%d]\n", value);

                value++;

                value = 9;
                if (write(client, &value, sizeof(value)) != sizeof(value)) {
                        printf("Client accept error [%s]\n", strerror(errno));
                        close(server);
                        return(-1);
                }
                printf("sent a value of [%d]\n", value);

                close(client);
        }
}
