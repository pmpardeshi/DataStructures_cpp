#include<iostream>
using namespace std;

void swap(int * num1, int * num2){
	/* do not use swapping without third variable logic 
		as pointer upon substraction subtracts address
		making both values zero and creating segmenntation fault
	*/
	int  temp=*num1;
	*num1=*num2;
	*num2=temp;
}

int partition(int * arr, int low, int high){
	
	int i = low-1 ; // for keeping track of lower values
	int pivot = arr[high];


	for(int j=0; j<=high; j++){

/*		if(arr[j]>pivot){
			//do nothing as we have to shift lower values to left
			// and ignore larger values
		}
*/
		if(arr[j]<pivot){
			i++;
			swap(arr[j],arr[i]);
		}

	}
	/*
		i points to last smaller element than pivot in array
		thus i+1 will point to larger element
	*/

	i++;
	swap(arr[high],arr[i]);
	return i;
}

void quicksort(int* arr, int low, int high){
	
	if(low<high){
		int border=partition(arr,low,high);
		quicksort(arr,low,border-1);
		quicksort(arr,border+1,high);
	}
}

int main(){
	//caller code
	int n;
	cout<<"enter size of array";
	cin>>n;
	cout<<"enter array ";

	int num_array[n];

	for(int i=0;i<n;i++){
		cin>>num_array[i];
	}

	cout<<"\n entered array ";


	for(int i=0;i<n;i++){
		cout<<num_array[i]<<" ";
	}

	


	quicksort(num_array,0,n-1);

		cout<<"\n sorted array ";

	for(int i=0;i<n;i++){
		cout<<num_array[i]<<" ";
	}

	return(0);
}