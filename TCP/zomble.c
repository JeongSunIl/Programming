#include <stdio.h>
#include <unistd.h>

int
main (){

    pid_t pid = fork();

    if(pid==0) puts("I am a child process");
    else {
        printf("Child Process : %d\n",pid);
        sleep(30);
    }

    if(pid == 0)
        puts("End child process");
    else 
        puts("End Parent process");

}

