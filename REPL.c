#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void REPL(){
    char buffer[128];
    ssize_t cmd;
    pid_t pid;

    cmd = read(STDIN_FILENO, buffer, sizeof(buffer)- 1);
    buffer[cmd - 1] = '\0';

    pid = fork();

    if (pid == 0) {

        write(STDOUT_FILENO,buffer, sizeof(buffer)-1);

    } else {
        wait(NULL);
        }
}   
