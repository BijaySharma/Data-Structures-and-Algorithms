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
  
  if(list.head == NULL){
    printf("List is Empty \n");
    return;
  }

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


void delete(struct List *list, int index){
  if(list->head == NULL){
    printf("Error: List is empty. \n");
    return;
  }

  struct Node *p, *temp;

  if(index == 1){
    temp = list->head;
    list->head = temp->next;
    
    if(list->tail == temp)
      list->tail = list->head;
    
    free(temp);
    return;
  }

  int i;
  p = list->head;
  for(i = 1; i<(index - 1); i++){
    p = p->next;
  }
  
  if(p == NULL || p->next == NULL){
    printf("Invaid Index \n");
  }

  temp = p->next;
  p->next = temp->next;

  if(list->tail == temp)
    list->tail = p;

  free(temp);
}

void deleteFromHead(struct List *list){
  if(list->head == NULL){
    printf("Error: List is empty. \n");
    return;
  }

  if(list->head == list->tail)
    list->tail = NULL;

  struct Node *temp = list->head;
  list->head = list->head->next;
  free(temp);
}

void deleteFromTail(struct List *list){
  if(list->head == NULL || list->tail == NULL){
    printf("Error: List is empty. \n");
    return;
  }

  if(list->head == list->tail){
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
  }

  int i;
  struct Node *p = list->head;
  
  for(i = 1; p->next != list->tail; i++)
    p = p->next;
  
  free(list->tail);
  p->next = NULL;
  list->tail = p;

}


int main(){
  struct List list = {NULL, NULL}; // create a new List
  insertAtHead(&list, 22);
  insertAtTail(&list, 5);
  insertAtTail(&list, 6);
  insertAtTail(&list, 7);
  insertAtHead(&list, 9);
  print(list);
  delete(&list, 5);
  print(list);
  insertAtTail(&list, 99);
  print(list);
  delete(&list, 1);
  print(list);
  deleteFromTail(&list);
  print(list);
  deleteFromHead(&list);
  print(list);
  deleteFromHead(&list);
  print(list);
  deleteFromHead(&list);
  print(list);

  return 0;
}