#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

void addQ (int); int deleteQ (); bool IsFull (); bool IsEmpty (); void print_queue ();


int queue[MAX_SIZE];
int front = 0;
int rear = 0;

int 
main (){

  printf("MAX_SIZE = %d\n",MAX_SIZE);
  printf("-------- ADD --------\n");
  addQ(1);
  addQ(2);
  addQ(3);
  addQ(4);
  addQ(5);
  
  print_queue();

  printf("-------- DELETE --------\n");
  deleteQ();
  deleteQ();
  deleteQ();

  print_queue();
  printf("-------- ADD -------\n");
  addQ(7);
  addQ(8);
  addQ(9);
  addQ(10);
  addQ(11);
  print_queue();

  printf("-------- DELETE --------\n");
  deleteQ();
  deleteQ();
  print_queue();

}

void addQ (int num){
    if(IsFull()){
        printf("OverFlow\n");
        exit(1);
     }

    rear = (rear+1)%MAX_SIZE;
    queue[rear] = num;
}

int deleteQ (){
    int result;
    if(IsEmpty()){
        printf("UnderFlow\n");
        exit(1);
    }

    front = (front+1)%MAX_SIZE;
    result = queue[front];
    queue[front] = '\0';
    return result;
}

bool IsFull(){
    return (rear+1)%MAX_SIZE == front ? true : false;
}

bool IsEmpty(){
    return rear == front ? true : false;
}

void print_queue(){
   int i;

    printf("Queue: [");
    for(i=front+1 ; i != (rear+1)%MAX_SIZE; i = (i+1)%MAX_SIZE){
        if((i+1)%MAX_SIZE == rear+1)
            printf(" %d",queue[i]);
        else
            printf(" %d,",queue[i]);
    }
    printf(" ]\n");
}
