#include<bits/stdc++.h>
using namespace std;

void topologicalsortutil(int G[][10], int v, int n, int visited[], stack<int> &s){
	visited[v] = 1;
	for(int i=0;i<n;++i){
		if(!visited[i] && G[v][i])
			topologicalsortutil(G, i, n, visited, s);
	}
	s.push(v);
}

void topologicalsort(int G[][10], int n){
	stack<int> s;
	int visited[n];
	for(int i=0;i<n;++i)
		visited[i] = 0;
	for(int i=0;i<n;++i){
		if(!visited[i])
			topologicalsortutil(G, i, n, visited, s);
	}
	cout<<"Topological Sort: ";
	while(!s.empty()){
		cout<<"\t"<<s.top();
		s.pop();
	}
}

int main(){
	int G[10][10], n;
	cout<<"Enter number of vertices: ";
	cin>>n;
	cout<<"Enter vertices: "<<endl;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>G[i][j];
	topologicalsort(G, n);
	cout<<endl;
	return 0;
}

/* Enter number of vertices: 6 
Enter vertices: 
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 1 0 0
0 1 0 0 0 0 
1 1 0 0 0 0
1 0 1 0 0 0
Topological Sort: 	5	4	2	3	1	0 */