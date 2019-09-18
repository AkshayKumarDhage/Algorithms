#include<bits/stdc++.h>
using namespace std;

bool iscyclicutil(int G[][10], int n, int v, int visited[], int recstack[]){
	if(!visited[v]){
		visited[v]=1;
		recstack[v]=1;
		for(int i=0;i<n;++i){
			if(!visited[i] && iscyclicutil(G, n, i, visited, recstack))
				return true;
			else if(recstack[i])
				return true;
		}
	}
	recstack[v] = false;
	return false;
}

bool iscyclic(int G[][10], int n){
	int visited[n], recstack[n];
	for(int i=0;i<n;++i){
		visited[i] = 0;
		recstack[i] = 0;
	}
	for(int i=0;i<n;++i)
		if(iscyclicutil(G, n, i, visited, recstack))
			return true;
	return false;
}

int main(){
	int G[10][10], n;
	cout<<"Enter number of vertices: ";
	cin>>n;
	cout<<"Enter vertices: "<<endl;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>G[i][j];
	bool ans = iscyclic(G, n);
	if(ans)
		cout<<"Is cyclic";
	else
		cout<<"Not Cyclic";
	cout<<endl;
	return 0;
}

/* Enter number of vertices: 4
Enter vertices: 
0 1 1 0
0 0 1 0
1 0 0 1
0 0 0 1
Is cyclic
*/