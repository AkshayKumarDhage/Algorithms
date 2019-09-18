#include<bits/stdc++.h>
using namespace std;

int min_distance(int distance[], int *visited, int n){
	int min_d = INT_MAX, min_index;
	for(int i=0;i<n;++i){
		if(!visited[i] && distance[i]<min_d){
			min_d = distance[i];
			min_index = i;
		}
	}
	return min_index;
}

void dijkstra(int G[][10], int n, int source){
	int visited[n], distance[n];
	for(int i=0;i<n;++i){
		visited[i] = 0;
		distance[i] = INT_MAX;
	}
	distance[0] = 0;

	for(int j=0;j<n-1;++j){
		int u = min_distance(distance, visited, n);
		visited[u] = 1;
		for(int i=0;i<n;++i){
			if(!visited[i] && G[u][i] && distance[u] != INT_MAX && distance[u] + G[u][i] < distance[i]){
				distance[i] = distance[u] + G[u][i];
			}
		}
	}
	cout<<"Vertex - Distance from source\n";
	for(int i=0;i<n;++i)
		cout<<i<<"\t\t"<<distance[i]<<endl;
}

int main(){
	int G[10][10], n, source;
	cout<<"Enter no. of vertices: ";
	cin>>n;
	cout<<"Enter the weighted matrix:\n";
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>G[i][j];
	source = 0;
	dijkstra(G, n, source);
	return 0;
}

/*Enter no. of vertices: 9 
Enter the weighted matrix:
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
Vertex - Distance from source
0		0
1		4
2		12
3		19
4		21
5		11
6		9
7		8
8		14
*/