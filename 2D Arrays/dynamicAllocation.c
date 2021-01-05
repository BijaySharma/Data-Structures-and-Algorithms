#include <stdio.h>
#include<stdlib.h>
int main(){
    
    int **arr;
    arr = (int **) malloc(3 * sizeof(int));
    for(int i = 0; i<3; i++){
        arr[i] = (int *) malloc(3 * sizeof(int));
    }
    
    for(int i = 0; i<3; i++){
        for(int j = 0; j < 3; j++){
            arr[i][j] = j+i;
        }
    }
    
    for(int i = 0; i<3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    

    return 0;
}
