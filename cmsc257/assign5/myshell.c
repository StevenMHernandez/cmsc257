#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

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

                // wait for input
                if (fgets(input, 51, stdin) != NULL)
                {
                        // remove useless "\n" from fgets
                        char *newline = strchr( input, '\n' );
                        if ( newline ) {
                                *newline = 0;
                        }

                        printf("%s|\n", input);

                        char *command = strtok(input, " ");

                        printf("%s|%s|\n", input, command);

                        char *parameters = strtok(NULL, input);

                        printf(":%s::%s\n", command, parameters);

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

                        } else if (strncmp(command, "pid", 3) == 0) {
                                printf("PID: %d\n", getpid());
                        } else if (strncmp(command, "ppid", 4) == 0) {
                                printf("PPID: %d\n", getppid());
                        } else {
                                // just exec
                                pid_t child_pid = fork();
                                if(child_pid == 0) {
                                        // execvp(command, &parameters);
                                        // char *const *s = malloc(10);
                                        // *s = "ls";
                                        // execvp("ls", s);

                                        char* arg[] = {command, parameters, NULL};
                                        execvp(arg[0],arg);

                                        printf("Command not found.\n");
                                        exit(0);
                                }
                                else {
                                        int child_status;
                                        pid_t tpid;
                                        do {
                                                tpid = wait(&child_status);
                                        } while(tpid != child_pid);
                                }
                        }
                }
        }

        printf("\n");
        return 0;
}
