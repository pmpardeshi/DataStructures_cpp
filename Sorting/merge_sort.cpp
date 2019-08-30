#include<iostream>
using namespace std;

void merge(int*arr,int leftIndex,int middleIndex,int rightIndex){
//if we calculate diff in left mid and right, mid will be excluded thus we add 1 in leftarrsize

	int leftArrSize=middleIndex-leftIndex+1;
	int rightArrSize=rightIndex-middleIndex;
	int leftArr[leftArrSize];
	int rightArr[rightArrSize];

	for(int i=0;i<leftArrSize;i++){
		leftArr[i]=arr[leftIndex+i];
	}

	for(int j=0;j<rightArrSize;j++){
		rightArr[j]=arr[middleIndex+1+j];
	}

	int j=0;
	int i=0;
	int k=leftIndex;

	while(i<leftArrSize && j<rightArrSize){
		if(leftArr[i]<=rightArr[j]){
			arr[k]=leftArr[i];
			i++;
		}
		else{
			arr[k]=rightArr[j];
			j++;
		}
		k++;
	}

	while(i<leftArrSize){
		arr[k]=leftArr[i];
		i++;
		k++;
	}

	while(i<rightArrSize){
		arr[k]=rightArr[j];
		j++;
		k++;
	}

}

void mergeSort(int* arr,int leftIndex,int rightIndex){
	if(leftIndex<rightIndex){

		int  middleIndex=leftIndex+(rightIndex-leftIndex)/2;
	/*
		mid=left+right/2=(left+right+left-left)/2=(2left+right-left)/2
		=left+(right-left)/2
		some times index could be so large that there addition may exceed limit of max value of datatype
		causing overflow bit.thus we improvise as above
	*/
		mergeSort(arr,leftIndex,middleIndex);
		mergeSort(arr,middleIndex+1,rightIndex);

		merge(arr,leftIndex,middleIndex,rightIndex);

	}
}

int main(){

	int n;
	cout<<"enter size on array ";
	cin>>n;

	int arr[n];

	cout<<"insert Array ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	mergeSort(arr,0,n-1);

	cout<<"sorted Array ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}