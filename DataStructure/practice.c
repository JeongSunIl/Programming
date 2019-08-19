#include <stdio.h>
#include <stdlib.h>

#define MAX 10


void push (int);
int pop();
void print_stack();

int stack[MAX];
int top = -1;

int
main (){
 push(1);
 push(2);
 push(3);
 print_stack();

 pop();
 print_stack();


}

void push (int num){

    if(top+1 == MAX){
        printf("stack is full");
        exit(1);
    }

    stack[++top] = num;
}

int pop (){

    if(top < 0){
        printf("stack is empty");
        exit(1);
    }

    return stack[top--];
}

void print_stack() {
    int i;

    for(i=0;i<top+1;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

