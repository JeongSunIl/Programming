#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void push (int);
int pop ();
void print_s ();

typedef struct node{
    int data;
    struct node* next;
}stack;


stack *top = NULL;

int
main (){

  printf("-------- PUSH --------\n");
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  
  print_s();

  printf("-------- POP --------\n");
  pop();
  pop();

  print_s();

}

void 
push (int data){

    stack *new_node = (stack*)malloc(sizeof(stack));

    if(new_node == NULL){
        printf("stack is full!");
        exit(1);
    }

    new_node -> data = data;
    new_node -> next = top;
    top = new_node;
}

int 
pop (){
    stack *del;
    int value;
    
    if(top == NULL){
        printf("stack is empty!");
        exit(1);
    }

    value = top -> data;
    del = top;
    top = top -> next;
    free(del);

    return value;
}

void 
print_s (){
    stack *i ;
    stack *count = top;

    i = count;

    while(i != NULL){
        if(i->next == NULL)
            printf("%d\n",i->data);
        else
            printf("%d --> ",i->data);

        i = count -> next;
        count = count -> next;
    }
}
