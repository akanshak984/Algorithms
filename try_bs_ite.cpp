/* Binary Search using Iteration */

#include <iostream>
using namespace std;

void bs(int arr[], int l, int h, int x){
	int mid;
	while(l<=h){
		mid = (l+h)/2;
		if(x==arr[mid]){
			cout<<x<<" is present at location "<<mid+1;
			break;
		}
		else if(x>arr[mid])
			l=mid+1;			
		else
			h=mid-1;	
	}
	if(l>h)
		cout<<x<<" is not present in the array";	
}

int main()
{
	int n, x;
	cout<<"Enter the size of array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the array elements (sorted): ";
	for (int i=0; i<n; i++)
		cin>>arr[i];
	cout<<"Enter the element to search: ";
	cin>>x;
	int l=0, h=n-1;
	bs(arr, l, h, x);
	return 0;
}
