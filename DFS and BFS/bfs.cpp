#include<bits/stdc++.h>
using namespace std;

void bfs(int G[10][10], int v, int n, int visited[], queue<int> q){
	if(!visited[v]){
		q.push(v);
		visited[v]=1;
		while(!q.empty()){
			int top = q.front();
			cout<<"\t"<<top;
			q.pop();
			for(int i=0;i<n;++i)
				if(!visited[i] && G[top][i]){
					q.push(i);
					visited[i]=1;
				}
		}
	}
}

void BFS(int G[10][10], int n){
	int visited[n], i, v;
	for(i=0;i<n;++i)
		visited[i] = 0;
	cout<<"Enter starting vertex: ";
	cin>>v;
	i = v;
	queue<int> q;
	cout<<"Graph is: ";
	do{
		if(!visited[i]){
			bfs(G, i, n, visited, q);
		}
		i = (i+1)%n;
	}while(i!=v);
}

int main(){
	int G[10][10], n;
	cout<<"Enter number of vertices: ";
	cin>>n;
	cout<<"Enter vertices: "<<endl;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>G[i][j];
	BFS(G, n);
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
DFS is: 	2	0	3	1
*/