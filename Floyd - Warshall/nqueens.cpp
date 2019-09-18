#include<bits/stdc++.h>
using namespace std;

bool is_safe(int board[][4], int row, int col){
	int i, j, n=4;

	//check row if queens in same row
	for(i=0;i<4;++i)
		if(board[row][i])
			return false;

	//check col if queen in same col
	for(i=0;i<4;++i)
		if(board[i][col])
			return false;

	//check upper left diagonal for queen
	for(i=row, j=col;i>=0 && j>=0; i--, j--)
		if(board[i][j])
			return false;

	//check upper right digonal for queen
	for(i=row, j=col;i>=0 && j<n; i--, j++)
		if(board[i][j])
			return false;

	//check lower left diagonal for queen
	for(i=row, j=col;i<n && j>=0; i++, j--)
		if(board[i][j])
			return false;

	//check lower right diagonal for queen
	for(i=row, j=col; i<n && j<n; i++, j++)
		if(board[i][j])
			return false;
}

bool nqueens(int board[][4], int col){
	if(col >= 4)
		return true;

	for(int i=0;i<4;++i){
		if(is_safe(board, i, col)){
			board[i][col] = 1;

			if( nqueens(board, col+1))
				return true;

			board[i][col] = 0;
		}
	}
	return false;
}

void print(int board[][4]){
	cout<<"The value 1 represent placement of queen:"<<endl;
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
	int board[4][4] = { {0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0} };

	if(!nqueens(board, 0))
		cout<<"Solution doesn't exist\n";
	else
		print(board);

	return 0;
}

/*The value 1 represent placement of queen:
0 0 1 0 
1 0 0 0 
0 0 0 1 
0 1 0 0 
*/