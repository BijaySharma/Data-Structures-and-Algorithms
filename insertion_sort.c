#include<stdio.h>
#include<conio.h>

// insertion sort function
void sort(int arr[], int n){
    // n is the size of array arr

    int value;
    int hole;

    for(int i=1; i<n; i++){
        value = arr[i];
        hole = i;
        while(hole > 0 && arr[hole-1] > value){
            arr[hole] = arr[hole-1];
            hole --;
        }
        arr[hole] = value;
    }

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