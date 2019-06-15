/* Coin changing problem using Dynamic Programming */

#include <iostream>
#define INF 999
using namespace std;

int n, A;

void coinChange(int d[], int S[], int C[]){
	int min, coin;
	for (int p=1; p<=A; p++){
		min = INF;
		for (int i=1; i<=n; i++){
			if(d[i]<=p){
				if(1+C[p-d[i]]<min){
					min = 1+C[p-d[i]];
					coin = i;
				}
			}
		}
		C[p]=min;
		S[p]=coin;
	}
}

void coinSet(int d[], int S[]){
	cout<<"The coins used are: ";
	while (A>0){
		cout<<d[S[A]]<<" ";
		A=A-d[S[A]];
	}	
}

int main(){
	cout<<"Enter the value for which you want change: ";
	cin>>A;
	cout<<"Enter the number of coins available for change: ";
	cin>>n;
	int S[A+1], C[A+1], d[n+1];
	cout<<"Enter the value of coins: ";
	d[0]=0, C[0]=0, S[0]=0;
	for (int i=1; i<=n; i++){
		cin>>d[i];
	}
	coinChange(d, S, C);
	coinSet(d, S);
	return 0;
}
