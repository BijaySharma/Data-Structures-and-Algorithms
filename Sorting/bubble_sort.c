#include<stdio.h>

void sort(int arr[], int s){

    int temp;
    int flag = 0;
    
    for(int i=0; i < s; i++){
        for(int j = 0; j < (s - i - 1); j++ ){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                flag = 1;
            }
        }
        if(flag == 0) break; //if there are no swaps in a pass that means that the array is sorted and we may end the loop.
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
	
				       
}