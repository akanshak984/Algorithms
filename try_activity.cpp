/* Activity Selection Problem */

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct activity{
	int st;
	int ft;
	int id;	
}activity;

bool compare(activity a, activity b)
{
	return a.ft < b.ft;
}

void selection(activity arr[], int n)
{
	int t;
	t = arr[0].ft;
	cout<<"Activities: "<<arr[0].id<<" ";
	for (int i=0; i<n; i++){
		if (arr[i].st>=t){
			cout<<arr[i].id<<" ";
			t = arr[i].ft;
		}
	}
}

int main(){
	int n;
	cout<<"Enter the number of activities: ";
	cin>>n;
	activity arr[n];
	cout<<"Enter the activity id, start time, finish time (id st fd)"<<endl;
	for (int i=0; i<n; i++){
		cin>>arr[i].id;
		cin>>arr[i].st;
		cin>>arr[i].ft;
	}
	sort(arr, arr+n, compare);
	selection(arr, n);
	return 0;
}

/*
Enter the number of activities: 8
Enter the activity id, start time, finish time (id st fd)
1 1 3
2 0 4
3 1 2
4 4 6
5 2 9
6 5 8
7 3 5
8 4 5
Activities: 3 7 6
--------------------------------
*/
