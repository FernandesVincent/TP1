#include <sys/types.h>
#include <unistd.h>
#include <string.h>  
#include "REPL.h"

#define WELCOME "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define PROMPT "enseash %  "
#define EXIT_MESSAGE "Bye Bye"

int main(){
    char buffer[128];
    ssize_t read_message;

    write(STDOUT_FILENO, WELCOME, strlen(WELCOME)); 

    while(1){
    write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

    read_message = read(STDIN_FILENO, buffer, sizeof(buffer)- 1);
    buffer[read_message - 1] = '\0';

    REPL();

    if(strcmp(buffer, "exit") == 0){
        write(STDOUT_FILENO, EXIT_MESSAGE, strlen(EXIT_MESSAGE));
        break; 
    }


    }
}









