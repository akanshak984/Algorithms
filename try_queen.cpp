/* n queen problem using Backtracking */

#include<iostream>
#include<math.h>
using namespace std;

int board[100]={0};
int n;

int canPlace(int row, int col){
	for (int i=0; i<row; i++){
		if (board[i]==col)
			return 0;
		if (abs(col-board[i])==abs(row-i))
			return 0;
	}
	return 1;
}

void nqueen(int row){
	for (int col=0; col<n; col++){
		if (canPlace(row, col)){
			board[row]=col;
			if (row==n-1){
				cout<<"\n\n";
				for (int i=0; i<n; i++){
					for (int j=0; j<n; j++){
						if (board[i]==j)
							cout<<"\t1";
						else
							cout<<"\t0";
					}
					cout<<endl;
				}
			}
			else
				nqueen(row+1);
		}
	}
}

int main(){
	cout<<"Enter the number of queens: ";
	cin>>n;
	nqueen(0);
	return 0;
}
