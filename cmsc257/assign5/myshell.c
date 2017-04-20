#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

char input[51];

int main(int argc, char const *argv[]) {
        while(1) {
                // decide prompt
                if (argc >= 3 && strncmp(argv[1], "-p", 2) == 0) {
                        printf("%s> ", argv[2]);
                } else {
                        printf("257sh> ");
                }
                fflush(stdout);

                // clear input
                input[0] = '\0';

                // wait for input
                if (fgets(input, 51, stdin) != NULL)
                {
                        if (input[0] != '\n') {
                                // remove useless "\n" from fgets
                                char *newline = strchr( input, '\n' );
                                if ( newline ) {
                                        *newline = 0;
                                }

                                // make a copy, so that we don't tokenize the parameters after the command
                                char copy[50];
                                strcpy(copy, input);

                                char *parameters;

                                char *command = strtok(input, " ");

                                parameters = (command) + strlen(command) + 1;

                                if (strncmp(command, "cd", 2) == 0) {
                                        if (parameters == NULL || strlen(parameters) == 0) {
                                                char *cwd = malloc(150);
                                                getcwd(cwd, 150);
                                                printf("%s\n", cwd);
                                                free(cwd);
                                        } else {
                                                chdir(parameters);
                                        }
                                } else if (strncmp(command, "exit", 4) == 0) {
                                        raise(SIGTERM);
                                } else if (strncmp(command, "pid", 3) == 0) {
                                        printf("PID: %d\n", getpid());
                                } else if (strncmp(command, "ppid", 4) == 0) {
                                        printf("PPID: %d\n", getppid());
                                } else {
                                        // just exec
                                        pid_t child_pid = fork();
                                        if(child_pid == 0) {
                                                char* arg[50];
                                                arg[0] = strtok(copy, " ");

                                                int i = 1;
                                                do {

                                                        arg[i] = strtok(NULL, " ");
                                                        i++;
                                                }
                                                while (arg[i - 1] != NULL);

                                                execvp(arg[0], arg);

                                                printf("Command not found.\n");
                                                exit(0);
                                        }
                                        else {
                                                int child_status;
                                                pid_t tpid;
                                                do {
                                                        tpid = wait(&child_status);
                                                } while(tpid != child_pid);
                                                printf("Exited with status: %d\n", child_status);
                                        }
                                }
                        }
                }
        }

        printf("\n");
        return 0;
}
