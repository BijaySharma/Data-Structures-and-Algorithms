#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void merge(int *A, int *L, int nL, int *R, int nR){
    
    int i = 0, j = 0, k = 0;

    while(i < nL && j < nR){

        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        k++;
    }

    //fill leftover array
    while(i < nL){
        A[k] = L[i];
        i++;
        k++;
    }

      while(j < nR){
        A[k] = R[j];
        j++;
        k++;
    }
}

void sort(int *A, int n){
    
    // base condition
    if(n < 2)
        return;
    
    int *L, *R;
    int mid;

    mid = n / 2; // mid index

    L = (int *) malloc(sizeof(int) * mid);
    R = (int *) malloc(sizeof(int) * (n-mid));

    for(int i = 0; i< mid; i++) // fill the left array
        L[i] = A[i];

    for(int i = mid; i<n; i++) // fill the right array
        R[i-mid] = A[i];

    // recursive call
    sort(L, mid);
    sort(R, n-mid);
    merge(A, L, mid, R, n-mid);

    // freeup allocated space after use.
    free(L);
    free(R);
}

void main(){
 
	// let us take any array a
	int a[] = {55,45,95,68,72,33,42,12,66,10,3,88,101,21};
	// size of this array is 4

	// displaying the values befor sorting
	printf("Array before sorting : ");
	for(int i=0; i < 14; i++){
		printf("%d, ", a[i]);
	}

	printf("\n");

	//sort
	sort(a, 14);

	//displaying the vlaues after sorting
	printf("Array after sorting : ");
	for(int i=0; i < 14; i++){
		
		printf("%d, ", a[i]);
	
	}
	printf("\n");
	
	getch();
				       
}