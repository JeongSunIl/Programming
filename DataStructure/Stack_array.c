#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_SIZE 1024


void
push (int);

int
pop ();

bool
IsFull ();

bool
IsEmpty ();

void 
print_stack ();

int top = -1;
int stack[MAX_SIZE] = {0,};

int
main (){
  printf("-------- Push --------\n");
  push(1);
  push(2);
  push(3);
  push(5);

  print_stack();

  printf("-------- pop --------\n");
  pop();
  pop();

  print_stack();
}

void push (int num){
    
    if(IsFull()){
        printf("\nStack Overflow");
        exit(1);
    }

    stack[++top] = num;
}

int pop (){
   
    if(IsEmpty()){
        printf("\n Stack Underflow");
        exit(1);
    }

    return stack[top--];
}

bool IsFull(){
   return (MAX_SIZE-1 == top) ?  true : false; 
}

bool IsEmpty(){
   return  (top < 0) ?  true : false;
}

    
void print_stack(){
    int i;
    
    printf("Stack : [");
    for(i=0;i<=top;i++){
        if(i == top) 
            printf(" %d",stack[i]);
        else
            printf(" %d,",stack[i]);
    }
    printf(" ]\n");
}
