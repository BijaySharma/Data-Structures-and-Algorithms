#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
  struct node *prev;
};
struct node *head;

struct node *getNewNode(int data){
  
  struct node *newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void insertAtHead(int data){
  struct node *newNode = getNewNode(data);

  if(head == NULL){
    head = newNode;
    return;
  }
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

void insertAtTail(int data){
  struct node *p = head;
  struct node *newNode = getNewNode(data);

  if(head == NULL){
    head = newNode;
    return;
  }

  while(p->next != NULL)
    p = p->next;

  p->next = newNode;
  newNode->prev = p;

}

void insert(int data, int pos){
  struct node *newNode = getNewNode(data);
  struct node *nextNode, *currentNode = head;
  if(pos == 1){
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return;
  }

  int i;
  for(i = 1; i < (pos-1) && currentNode != NULL; i++){
    currentNode = currentNode->next;
  }

  if(currentNode == NULL){
    printf("Invalid Index \n");
    return;
  }

  nextNode = currentNode->next;  
  if(nextNode == NULL){
    newNode->prev = currentNode;
    currentNode->next = newNode;
    return;
  }
  
  
  newNode->next = nextNode;
  newNode->prev = currentNode;

  nextNode->prev = newNode;
  currentNode->next = newNode;

}

void deleteFromTail(){
  struct node *p;
  p = head;
  if(head == NULL){
    printf("Opreation failed. The list is empty. \n");
    return;
  }
  // get the last node;
  while(p->next != NULL)
    p = p->next;
    
  struct node *previousNode = p->prev;
  previousNode->next = NULL;

  free(p);
}

void deleteFromHead(){
  if(head == NULL){
    printf("Opreation failed. The list is empty. \n");
    return;
  }

  struct node *p = head->next;
  if(p != NULL)
    p->prev = NULL;
  
  free(head);
  head = p;

}

void delete(int pos){

  if(head == NULL){
    printf("Opreation Failed. The list is empty \n");
    return;
  }
  struct node *currentNode, *previousNode, *nextNode;
  currentNode = head;

  if(pos == 1){
    nextNode = currentNode->next;
    nextNode->prev = NULL;
    head = nextNode;
    free(currentNode);
    return;
  }

  for(int i = 1; i < (pos) && currentNode != NULL; i++)
    currentNode = currentNode->next;

  
  if(currentNode == NULL){
    printf("\n Invalid Index \n");
    return;
  }

  nextNode = currentNode->next;
  previousNode = currentNode->prev;

  if(nextNode != NULL)
    nextNode->prev = previousNode;
  
  previousNode->next = nextNode;

  free(currentNode);
  

}

void print(){
  struct node *p;
  p = head;
  while(p != NULL){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

void reversePrint(){
  struct node *p = head;

  while(p->next != NULL)
    p = p->next;

  while(p != NULL){
    printf("%d ", p->data);
    p = p->prev;
  }

  printf("\n");
}

int main(){

  head = NULL; // initalize head pointer of linked list to null
  
  insertAtTail(2);
  insertAtTail(4);
  insertAtTail(6);
  insertAtTail(8);
  insertAtTail(10);
  insertAtHead(1);
  
  print();
  reversePrint();
  
  delete(3);
  print();

  insert(9, 5);
  print();

  deleteFromTail();
  print();

  deleteFromHead();
  print();

  reversePrint();


  return 0;
}