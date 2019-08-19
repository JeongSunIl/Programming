#include <stdio.h>
#include <unistd.h>

int gval = 10;

int
main (int argc, char *argv[]){
    pid_t pid;
    int lval = 100;
    
    gval += 1;
    lval += 1;

    pid = fork();

    if(pid == 0) gval += 10, lval += 10;
    else gval -= 10, lval -= 10;

    if(pid == 0) printf("Child proc: [%d, %d]\n",gval, lval);
    else printf("Parent proc: [%d, %d]\n", gval, lval);

}
