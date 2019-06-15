/* 0/1 knapsack using Dynamic Programming */

#include <iostream>
using namespace std;

void knapsack(int n, int m, int p[], int w[]){
	int  v[n+1][m+1];
	int ans[n];
	for (int i=0; i<=m; i++)  	 // 1st row 0
		v[0][i]=0;
	for (int i=0; i<=n; i++){    // 1st column 0
		v[i][0]=0;
		ans[i]=0;
	}	
	for (int i=1; i<=n; i++){   // fill other value of matrix
		for (int j=1; j<=m; j++){
			if(w[i]>j)
				v[i][j]=v[i-1][j];
			else
				v[i][j]=max(p[i]+v[i-1][j-w[i]], v[i-1][j]);		
		}
	}		
	cout<<"Matrix"<<endl;
	for (int i=0; i<=n; i++){
		for (int j=0; j<=m; j++){
			cout<<v[i][j]<<" ";
		}
		cout<<"\n";
	}	
	cout<<"Profit: "<<v[n][m]<<endl;	
	//select the items
	for (int i=n; i>0; i--){
		if (v[i][m]!=v[i-1][m]){
			ans[i-1]=1;
			m=m-w[i];
		}
	}	
	cout<<"Answer"<<endl<<"[ ";
	for (int i=0; i<n; i++){
		cout<<ans[i]<<" ";	
	}
	cout<<"]";
}

int main(){
	int n, m;
	cout<<"Enter the capacity of sack: ";
	cin>>m;
	cout<<"Enter the number of items: ";
	cin>>n;
	int p[n], w[n];
	cout<<"Enter the profit and weight of n items: "<<endl;
	for (int i=1; i<n+1; i++){
		cin>>p[i];
		cin>>w[i];
	}
	knapsack(n, m, p, w);
	return 0;
}
