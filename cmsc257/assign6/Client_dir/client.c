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

char input[51];

int main(int argc, char const *argv[]) {
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
        if (write(socket_fd, &value, sizeof(value)) != sizeof(value)) {
                printf("error writing network data [%s]\n", strerror(errno));
        }
        printf("sent a value of [%d]\n", ntohl(value));

        if (read(socket_fd, &value, sizeof(value)) != sizeof(value)) {
                printf("error writing network data [%s]\n", strerror(errno));
        }

        value = ntohl(value);
        printf("received a value of [%d]\n", value);

        close(socket_fd);
        return (0);
}
