#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void
timeout (int sig){
    if(sig == SIGALRM)
        puts("Time out!");
    alarm(2);
}

void
keycontrol (int sig){
    if(sig == SIGINT)
        puts("CTRL+C pressed");
}

int
main (int argc, char *argv[]){ //void (*signal(int signo, void(*func)(int)))(int);
    int i;
    signal(SIGALRM, timeout);
    signal(SIGINT, keycontrol);
