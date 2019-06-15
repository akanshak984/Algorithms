#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
	int i=0, j=0, k=low;
	int n1 = mid-low+1;
	int n2 = high-mid;
	int L[n1], R[n2];
	for (int i=0; i<n1; i++)
		L[i]=arr[low+i];
	for (int j=0; j<n2; j++)
		R[j]=arr[mid+1+j];
	while (i<n1 && j<n2){
		if (L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while (i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while (j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}	
}

void mergeSort(int arr[], int low, int high){
	int mid;
	if (low<high){
		mid=(low+high)/2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}	
}

int main(){
	int n;
	cout<<"Enter the size of the array ";
	cin>>n;
	int arr[n];
	cout<<"Enter the array elements: ";
	for (int i=0; i<n; i++){
		cin>>arr[i];
	}
	mergeSort(arr, 0, n-1);
	cout<<"Sorted array "<<endl;
	for (int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
