#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

void add (int); int right_delete (); int left_delete();  bool IsFull (); bool IsEmpty (); void print_deque();

int front = 0;
int rear = 0;
int deque[MAX];

int 
main (){
  printf("MAX_SIZE = %d\n",MAX);
  printf("-------- ADD --------\n");
  add(1);
  add(2);
  add(3);
  add(4);
  add(5);

  print_deque();

  printf("-------- LEFT_DELETE --------\n");
  left_delete();
  left_delete();
  left_delete();

  print_deque();
  printf("-------- ADD -------\n");
  add(7);
  add(8);
  add(9);
  add(10);
  add(11);
  print_deque();

  printf("-------- RIGHT_DELETE --------\n");
  right_delete();
  right_delete();
  print_deque();

}

void 
add (int num){
    if(IsFull()){
        printf("deque is full!\n");
        exit(1);
    }

    rear = (rear+1)%MAX;
    deque[rear] = num;
}

int 
left_delete (){
    int result;
    if(IsEmpty()){
        printf("deque is empty!\n");
        exit(1);
    }

    front = (front+1)%MAX;
    return deque[front];
     
}

int
right_delete (){
    if(IsEmpty()){
        printf("deque is empty!\n");
        exit(1);
    }
    
    if(rear == 0){
        rear = MAX - 1;
    }
    else rear = rear-1;
    return deque[rear];
}

bool 
IsFull() {
    return (rear+1)%MAX == front ? true : false;
}

bool 
IsEmpty() {
    return front == rear ? true : false;
}
    
void
print_deque (){
   int i;

    printf("Queue: [");
    for(i=(front+1)%MAX ; i != (rear+1)%MAX; i = (i+1)%MAX){
        if((i+1)%MAX == rear+1)
            printf(" %d",deque[i]);
        else
            printf(" %d,",deque[i]);
    }
    printf(" ]\n");
}
