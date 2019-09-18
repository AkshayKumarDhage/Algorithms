#include<bits/stdc++.h>
using namespace std;

void dfs(int G[10][10], int v, int n, int visited[]){
	if(!visited[v]){
		cout<<"\t"<<v;
		visited[v]=1;
		for(int i=0;i<n;++i)
			if(!visited[i] && G[v][i])
				dfs(G, i, n, visited);
	}
}

void DFS(int G[10][10], int n){
	int visited[n], i;
	for(i=0;i<n;++i)
		visited[i] = 0;
	int v;
	cout<<"Enter the starting vertix: ";
	cin>>v;
	cout<<"DFS is: ";
	i = v;
	do{
		if(!visited[i]){
			dfs(G, i, n, visited);
		}
		i = (i + 1)%n;
	}while(i!=v);
}

int main(){
	int G[10][10], n, i, j;
	cout<<"enter no. of vertices: ";
	cin>>n;
	cout<<"Enter the vertices: "<<endl;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			cin>>G[i][j];
	DFS(G,n);
	cout<<endl;
	return 0;
}

/* enter no. of vertices: 4
Enter the vertices: 
0 1 1 0
0 0 1 0
1 0 0 1
0 0 0 1
Enter the starting vertix: 2
DFS is: 	2	0	1	3
*/