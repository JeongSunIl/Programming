#include <stdio.h>
#include <stdlib.h>

void add (int); int delete(); void Print();

typedef struct node{
    int data;
    struct node *next;
}queue;

queue *rear = NULL;
queue *front = NULL;

int 
main () {
    printf("----- ADD -----\n");
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);

    Print();

    printf("----- DELETE -----\n");

    delete();
    delete();
    delete();

    Print();

}

void 
add (int data) {
    queue *new_node = (queue*)malloc(sizeof(queue));
    
    new_node -> data = data;
    new_node -> next = NULL;

    if(rear == NULL && front == NULL){
         front = new_node;
         rear = new_node;
         return;
    }

    rear -> next = new_node;
    rear = new_node;

};

int 
delete (){
    int re;
    queue * del = (queue*)malloc(sizeof(queue));
    
    if(front == NULL && rear == NULL){ 
        printf("queue is empty!!\n");
        exit(1);
    }
    del = front;
    front = front -> next;
    re = del ->data;
    free(del);

    return re;
}

void Print() {
    queue * temp = front;
    while(temp != NULL){
        if( temp == rear){
            printf("%d",temp->data);
        }
        else{
            printf("%d --> ", temp->data);
        }
        temp = temp ->next;
    }
        printf("\n");
        

}
    
