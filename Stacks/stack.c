#include<stdio.h>
#define MAX_SIZE 10

int A[MAX_SIZE];
int top = -1;

int isFull(){
  if(top == (MAX_SIZE - 1))
    return 1;
  else
    return 0;
}

int isEmpty(){
  if(top == -1)
    return 1;
  else
    return 0;
}

void push(int x){
  if(isFull() == 1){
    printf("Error: Stack is Full\n");
    return;
  }
  A[++top] = x;
}

void pop(){
  if(isEmpty()){
    printf("Error: Stack is Empty \n");
    return;
  }
  top--;
}

void peek(){
  if(isEmpty()){
    printf("Error : Stack is Empty \n");
    return;
  }
  printf("%d \n", A[top]);
}

int main() {
  push(5);
  push(8);
  push(10);
  peek();
  pop();
  peek();

  return 0;
}