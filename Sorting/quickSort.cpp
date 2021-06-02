#include<iostream>
using namespace std;

int partition(int A[],int start,int end){
    int partitionIndex = start;
    int pivot = A[end];
    int temp;

    for(int i = start; i < end; i++){
        if(A[i] < pivot){
            temp = A[i];
            A[i] = A[partitionIndex];
            A[partitionIndex] = temp;
            partitionIndex++;
        }
    }

    temp = A[partitionIndex];
    A[partitionIndex] = pivot;
    A[end] = temp;


    return partitionIndex;
}

void quickSort(int A[],int start,int end){
    
    if( start >= end ) return;

    int pIndex = partition(A, start, end);
    quickSort(A, start, pIndex -1);
    quickSort(A, pIndex + 1, end);
}

int main(){

    int A[] = { 8, 12, 6, 2, 44, 7, 16, 3, 9, 15 };
    quickSort(A, 0, 9);
    
    for (int i = 0; i < 10; i++){
        cout<< A[i] << "  ";    
    }
    

    return 0;
}