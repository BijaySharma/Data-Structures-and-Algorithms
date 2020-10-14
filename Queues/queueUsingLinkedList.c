#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *front, *rear;

void enqueue(int x){
 
  struct Node *newNode;
  newNode = (struct Node *) malloc(sizeof(struct Node));
 
  if(newNode == NULL){
    printf("Error: Queue is full. \n");
    return;
  }

  newNode->data = x;
  newNode->next = NULL;

  if(front == NULL)
    front = rear = newNode;
  else{
    rear->next = newNode;
    rear = newNode;
  }
  
}

int dequeue(){
  int x = -1;
  struct Node *t;
  
  if(front == NULL){
    printf("Error: Queue is Empty. \n");
    return x;
  }

  x = front->data;
  t = front;
  front = front->next;
  free(t);

  return x;
}

void display(){
  struct Node *p = front;
  while(p != NULL){
    printf("%d ", p->data);
    p = p->next;
  }

  printf("\n");
}

void displayFront(){
  if(front == NULL)
    printf("Error: Queue is Empty. \n");
  else
    printf("Front = %d \n", front->data);
}

int main(){
  front = rear = NULL; // initialze the list
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
        enqueue(item);
        break;

      case 2:
        x = dequeue();
        if(x != -1) printf("%d has been removed from queue. \n", x);
        break;

      case 3:
        displayFront();
        break;
      
      case 4: 
        printf("Queue = ");
        display();
        break;

      case 5:
        exit(1);
    }
  }
 
  return 0;
}