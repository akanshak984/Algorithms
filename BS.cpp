// Binary Search using Recursion

#include <iostream>
#include <algorithm>
using namespace std;

// function to search recursively
void binary(int l[], int low, int high, int x)
{
	int mid;
	mid = (low+high)/2;
	if(low <= high)
	{
		if(l[mid] < x)          // search element is greater than mid element
		{
			low = mid+1;
			binary(l,low,high,x);
		}
		else if(l[mid] == x)     // search element is equal to mid element
		{
		 	cout<<x<<" is present in the array "<<endl;  // element found
		} 
		else                    // search element is smaller than mid element
		{ 
			high = mid-1; 
			binary(l,low,high,x);
		} 
    } 
    else
	{
		cout<<x<<" is not present in the array";    // element not found
	}			
}

int main()    // main function
{
	int x, n;
	int l[40];
	int low, high;
	low=0;
	cout<<"Enter the size of array: ";  // input size of array
	cin>>n;
	high=n-1;
	cout<<"Enter the elements of array: "<<endl;  // input array 
	for (int i=0; i<n; i++)
	{
		cin>>l[i];
	}
	sort(l,l+n);    // sort the array elements
	cout<<"Enter the element to search: ";   // input element to search
	cin>>x;
	binary(l,low,high,x);    // calling function to search
	return 0;
}

/*
-------------OUTPUT-------------
Enter the size of array: 5
Enter the elements of array:
1 5 4 3 2
Enter the element to search: 3
3 is present in the array
--------------------------------
Enter the size of array: 6
Enter the elements of array:
1 4 5 8 7 3
Enter the element to search: 9
9 is not present in the array
*/
