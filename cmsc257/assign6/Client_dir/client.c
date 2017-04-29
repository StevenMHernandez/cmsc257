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
        if (argc < 2) {
                printf("ERROR: please input a filename.\n");
                return(-1);
        }

        strcpy(input, argv[1]);

        int socket_fd;
        uint32_t value;
        struct sockaddr_in caddr;
        char *ip = "127.0.0.1";

        caddr.sin_family = AF_INET;
        caddr.sin_port = htons(2223);
        if (inet_aton(ip, &caddr.sin_addr) == 0) {
                return(-1);
        }

        socket_fd = socket(PF_INET, SOCK_STREAM, 0);
        if (socket_fd == -1) {
                printf("Socket creation error [%s]\n", strerror(errno));
                return(-1);
        }

        if (connect(socket_fd, (const struct sockaddr *)&caddr, sizeof(struct sockaddr)) == -1) {
                printf("socket connection error [%s]\n", strerror(errno));
                return (-1);
        }

        value = htonl(1);
        if (write(socket_fd, &input, strlen(input)) != strlen(input)) {
                printf("error writing network data [%s]\n", strerror(errno));
        }
        printf("sent a value of [%s]\n", input);

        // Receive confirmation from server that file exists or not
        if (read(socket_fd, &value, sizeof(value)) != sizeof(value)) {
                printf("error reading network data [%s]\n", strerror(errno));
        }
        value = ntohl(value);

        if (value == FILE_EXISTS) {
                printf("File exists, receiving file.\n");

                FILE *file = fopen(argv[1], "w+");
                while (read(socket_fd, &input, 50) && strcmp(input, "cmsc257") != 0) {
                        fputs(input,file);
                };

                if (strcmp(input, "cmsc257") != 0) {
                        printf("Server process was terminated. File transfer stopping.\n");
                } else {
                        printf("File downloaded.\n");
                }
        } else if (value == FILE_NOT_FOUND) {
                printf("File not found on the server.\n");
        }

        close(socket_fd);
        return (0);
}
