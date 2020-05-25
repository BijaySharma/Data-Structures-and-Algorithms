#include<stdio.h>
#include<conion.h>

void merge(int a[], int left[], int right[]){
    
    // finding the size of each array
    int nL = sizeof left / sizeof int;
    int nR = sizeof right / sizeof int;
    int nA = sizeof a / sizeof int;

    /* 
    Let, i mark the smallest unpicked in left[]
         j mark the smallest unpicked in right[]
         k mark the index of a[] 
    */
    int i = 0, j = 0, k = 0;

    while(i < nL && j < nR){

        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        }else{
            a[k] = right[j];
            j++;
        }
        k++;
    }

    // in case we exhaust one of any two divided arrays - then we shall fill the contents of the other non exhausted array
    // only one of the two while loops will execute. Since only one sub array will be left over
    while(i < nL){
        a[k] = left[i];
        i++;
        k++;
    }

      while(j < nR){
        a[k] = right[j];
        j++;
        k++;
    }
}