#include<bits/stdc++.h>
using namespace std;

void warshall(int a[][10], int n){
	int d[n][n];

	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			d[i][j] = a[i][j];

	for(int k=0;k<n;++k)
		for(int j=0;j<n;++j)
			for(int i=0;i<n;++i)
				d[i][j] = d[i][j] || (d[i][k] && d[k][j]);

	cout<<"\nTransitive closure matrix:"<<endl;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			cout<<d[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
	int a[10][10], n;
	cout<<"Enter n: ";
	cin>>n;

	cout<<"Enter adjacency matrix:"<<endl;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>a[i][j];

	warshall(a, n);
	return 0;
}

/*Enter n: 4
Enter adjacency matrix:
1 1 0 1
0 1 1 0
0 0 1 1
0 0 0 1

Transitive closure matrix:
1 1 1 1 
0 1 1 1 
0 0 1 1 
0 0 0 1 */