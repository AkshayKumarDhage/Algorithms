#include<bits/stdc++.h>
using namespace std;

void floyd(int a[][10], int n){
	int d[n][n];

	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			d[i][j] = a[i][j];

	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

	cout<<"\nResulting distance matrix:"<<endl;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			if(d[i][j]==999)
				cout<<"INF"<<" ";
			else
				cout<<d[i][j]<<"   ";
		cout<<endl;
	}	
}

int main(){
	int a[10][10], n;
	cout<<"Enter n: ";
	cin>>n;

	cout<<"Enter the weighted matrix:"<<endl;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>a[i][j];

	floyd(a, n);
	return 0; 
}

/*Enter n: 4
Enter the weighted matrix:
0 5 999 10
999 0 3 999
999 999 0 1
999 999 999 0

Resulting distance matrix:
0   5   8   9   
INF 0   3   4   
INF INF 0   1   
INF INF INF 0 */