#include<stdio.h>
#include<stdlib.h>

struct Queue{
  int size;
  int front;
  int rear;
  int *Q;
};

void initialize(struct Queue *q, int size){
  q->size = size;
  q->front = q-> rear = -1;
  q->Q = (int *) malloc(sizeof(int) * size); 
}

void enqueue(struct Queue *q ,int x){
  if(q->rear == (q->size - 1))
    printf("Error: Queue if full. \n");
  else {
    q->rear++;
    q->Q[q->rear] = x;
  }
}

int dequeue(struct Queue *q){
  int x = -1;
  
  if(q->front == q->rear){
    printf("Error: Queue is empty. \n");
    return x;
  }

  q->front++;
  x = q->Q[q->front];
  return x;
}

void display(struct Queue q){
  int i;
  
  for(i = q.front + 1; i <= q.rear; i++)
    printf("%d ", q.Q[i]);

  printf("\n");
}

int main(){
  struct Queue q;
  initialize(&q, 5);

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  
  display(q);

  printf("%d \n", dequeue(&q));
  
  return 0;
}