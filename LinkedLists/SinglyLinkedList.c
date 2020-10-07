#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

struct List{
  struct Node *head;
  struct Node *tail;
};

struct Node *getNewNode(int data){
  struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void print(struct List list){
  struct Node *p = list.head;
  while(p != NULL){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

void insertAtTail(struct List *list, int data){
  struct Node *newNode = getNewNode(data);

  if(list->head == NULL){
    list->head = newNode;
    list->tail = list->head;
    return;
  }

  list->tail->next = newNode;
  list->tail = newNode;
}

void insertAtHead(struct List *list, int data){
  struct Node *newNode = getNewNode(data);
 
  if(list->head == NULL)
    list->tail = newNode;

  newNode->next = list->head;
  list->head = newNode;
}

// TODO Delete
// void delete(struct List *list, int index){
//   if(list->head == NULL){
//     printf("Error: List is empty. \n");
//     return;
//   }

//   int i;
//   struct Node *p = list->head;
//   for(i = 1; i<index; i++){
//     p = p->next;
//   }

// }


int main(){
  struct List list = {NULL, NULL}; // create a new List
  insertAtHead(&list, 22);
  insertAtTail(&list, 5);
  insertAtTail(&list, 6);
  insertAtTail(&list, 7);
  insertAtHead(&list, 9);
  print(list);
  return 0;
}