//Name -Amandeep , CSE-44 , Roll No - 2205967

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGUMENTS];

    while (1) {
        
        printf("Shell> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        
        
        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

       
        char* token = strtok(command, " ");
        int arg_count = 0;
        while (token != NULL && arg_count < MAX_ARGUMENTS - 1) {
            args[arg_count] = token;
            token = strtok(NULL, " ");
            arg_count++;
        }
        args[arg_count] = NULL; // Null-terminate the argument list
        
    
        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (arg_count > 1) {
                chdir(args[1]);
            } else {
                printf("Usage: cd <directory>\n");
            }
            continue;
        } else if (strcmp(args[0], "history") == 0) {
            // Implement history functionality
            continue;
        }

        
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("execvp failed");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}
