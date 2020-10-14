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

void displayFront(struct Queue *q){
  if(isEmpty(q)){
    printf("Error: Queue is empty. \n");
  }else{
    int index = (q->front + 1) % q->size;
    printf("Front = %d \n", q->Q[index]);
  }
}

int main(){
  struct Queue q;
  initialize(&q, 5);

  int choice, item, x;
  while(1 == 1){
    
    printf("\n");
    printf("1: Enqueue \n");
    printf("2: Dequeue \n");
    printf("3: Front \n");
    printf("4: Display \n");
    printf("5: Exit \n");

    printf("Enter a choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Enter Item: ");
        scanf("%d", &item);
        enqueue(&q, item);
        break;

      case 2:
        x = dequeue(&q);
        if(x != -1) printf("%d has been removed from queue. \n", x);
        break;

      case 3:
        displayFront(&q);
        break;
      
      case 4: 
        printf("Queue = ");
        display(q);
        break;

      case 5:
        exit(1);
    }
  }
 

  return 0;
}