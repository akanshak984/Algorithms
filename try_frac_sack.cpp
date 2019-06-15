/* Fractional Knapsack using greedy method */

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct item{
	int id;
	int profit;
	int weight;
	float pbw;
}item;

bool compare(item a, item b){
	return a.pbw>b.pbw;
}

void knapsack(item arr[], int n, int m){
	float profit = 0.0;
	int i;
	float answer[n]={0};
	for (i=0; i<n; i++){
		if (arr[i].weight>m)
			break;
		answer[arr[i].id]=1.0;
		m=m-arr[i].weight;
		profit=profit+arr[i].profit;
	}
	if(i<=n){
		answer[arr[i].id]=(float)m/arr[i].weight;
		profit=profit+answer[arr[i].id]*arr[i].profit;
	}
	cout<<"Total profit obtained is: "<<profit;
	cout<<"\nItems selected are"<<endl<<"[";
	for (int i=0; i<n; i++){
		cout<<answer[i]<<" ";
	}
	cout<<"]";
}

int main()
{
	int n, m;
	cout<<"Enter the capacity of the sack: ";
	cin>>m;
	cout<<"Enter the number of item? ";
	cin>>n;
	item arr[n];
	cout<<"Enter the profit, weight of the items"<<endl;
	for (int i=0; i<n; i++){
		arr[i].id=i;
		cin>>arr[i].profit;
		cin>>arr[i].weight;
		arr[i].pbw = (float) arr[i].profit/arr[i].weight;
	}
	sort(arr,arr+n,compare);
	knapsack(arr, n, m);
	return 0;
}

/*
Enter the capacity of the sack: 20
Enter the number of item? 3
Enter the profit, weight of the items
25 18
24 15
15 10
Total profit obtained is: 31.5
Items selected are
[0 1 0.5 ]
--------------------------------
*/
