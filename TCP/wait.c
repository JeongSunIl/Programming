#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main () {
    pid_t pid = fork();
    int status;

    if(pid == 0)
        return 3;
    else{
        printf("Child pid1: %d\n",pid);
        pid = fork();
        printf("Child pid2: %d\n",pid);
        if(pid ==0) exit(7);
        else{
            printf("Child pid3: %d\n",pid);
            wait(&status);
            if(WIFEXITED(status))
                printf("Child send one: %d \n", WEXITSTATUS(status));

            wait(&status);
            if(WIFEXITED(status))
                printf("Child send two: %d \n", WEXITSTATUS(status));
        }
    }
}
