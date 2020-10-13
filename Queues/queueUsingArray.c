#include<stdio.h>
#include<stdlib.h>

struct Queue{
  int size;
  int front;
  int rear;
  int *Q;
};

int isFull(struct Queue *q){
  return ((q->rear + 1) % q->size == q->front); 
}

int isEmpty(struct Queue *q){
  return (q->front == q->rear);
}

void initialize(struct Queue *q, int size){
  q->size = size;
  q->front = q-> rear = 0;
  q->Q = (int *) malloc(sizeof(int) * size); 
}

void enqueue(struct Queue *q ,int x){
  if(isFull(q))
    printf("Error: Queue if full. \n");
  else {
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
  }
}

int dequeue(struct Queue *q){
  int x = -1;
  
  if(isEmpty(q)){
    printf("Error: Queue is empty. \n");
    return x;
  }

  q->front = (q->front + 1) % q->size;
  x = q->Q[q->front];
  return x;
}

void display(struct Queue q){
  int i = q.front + 1;
  
  do{
    printf("%d ", q.Q[i]);
    i = (i+1) % q.size;
  }while(i != (q.rear + 1) % q.size);

  printf("\n");
}

int main(){
  struct Queue q;
  initialize(&q, 5);

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  enqueue(&q, 40);
  enqueue(&q, 50);
  enqueue(&q, 60);

  // for a queue of size N the elements that can be inserted is (N-1)
  
  display(q);

  printf("%d \n", dequeue(&q));

  return 0;
}