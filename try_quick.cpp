/* Quick Sort Algorithm using the 1st element as pivot */

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high){
	int pivot, i, j, temp;
	pivot=arr[low];
	i=low;
	j=high+1;
	do{
		do{
			i++;
		}while(arr[i]<pivot && i<=high);
		do{
			j--;
		}while(arr[j]>pivot);
		if(i<j){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}while(i<j);
	arr[low]=arr[j];
	arr[j]=pivot;
	return j;
}

void quickSort(int arr[], int low, int high){
	int j;
	if (low<high){
		j = partition(arr, low, high);
		quickSort(arr, low, j-1);
		quickSort(arr, j+1, high);
	}
}

int main(){
	int n;
	cout<<"Enter the size of array ";
	cin>>n;
	int arr[n];
	cout<<"Enter the array elements: ";
	for (int i=0; i<n; i++){
		cin>>arr[i];
	}
	quickSort(arr, 0, n-1);
	cout<<"Sorted array: "<<endl;
	for (int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	return 0;
}
