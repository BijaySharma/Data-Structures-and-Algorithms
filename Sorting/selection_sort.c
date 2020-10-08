#include<stdio.h>
#include<conio.h>

//selection sort function
void sort(int arr[], int s){
	
	int temp;
	
	for(int i = 0; i < (s-1); i++){
		
		for(int j = i; j < s; j++){
		
			if(arr[j] < arr[i]){
				//swap
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		
		}	

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
