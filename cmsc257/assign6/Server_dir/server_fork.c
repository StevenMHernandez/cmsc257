#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define FILE_NOT_FOUND 0
#define FILE_EXISTS 1

int errno = 3;

char input[51];

pid_t child_pid;

int server, client;

void signal_handler(int no) {
        if (child_pid) {
                printf("\nTerminating now.\n");
        }
        close(server);
        close(client);
        raise(SIGKILL);
}

int main(int argc, char const *argv[]) {
        signal(SIGINT, signal_handler);
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

                child_pid = fork();
                if (child_pid == 0) {
                        // run in child process
			int count = read(client, &input, 50);
			input[count] = '\0';
                        printf("received a value of [%s]\n", input);

                        // check if file exists
                        // @SEE http://stackoverflow.com/a/230068
                        value = ntohl(access(input, F_OK) != -1);

                        if (write(client, &value, sizeof(value)) != sizeof(value)) {
                                printf("Client accept error\n");
                                close(server);
                                return(-1);
                        }

                        if (htonl(value) == FILE_EXISTS) {
                                printf("File exists, starting transfer\n");
                                FILE *file = fopen(input, "r+");
                                while (fgets(input, 50, file) != NULL) {
                                        write(client, &input, 50);
                                }
                                strcpy(input, "cmsc257");
                                write(client, &input, 50);
                                printf("Transfer complete\n\n");
                        } else {
                                printf("File does not exists, closing.\n\n");
                        }

                        close(client);

                        _exit(0);
                } else {

                }
        }
}
