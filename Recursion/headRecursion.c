#include<stdio.h>

void fun(int x){
  if(x > 0){
    fun(x-1);
    printf("%d ", x);
  }
}

int main(){
  int x = 3;
  fun(3);

  return 0;
}