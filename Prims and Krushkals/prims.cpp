#include<bits/stdc++.h>
using namespace std;

int min_distance_vertex_index(int min_distances[], bool included_vertex[], int n){
	int min= INT_MAX, min_index;
	for(int i=0; i<n; ++i){
		if( !included_vertex[i] && min_distances[i] < min){
			min = min_distances[i];
			min_index = i;
		}
	}
	return min_index;
}

void prims(int G[][10], int n){
	int parent[n], min_distances[n], i, j;
	bool included_vertex[n];
	for(i=0; i<n; ++i){
		min_distances[i] = INT_MAX;
		included_vertex[i] = false;
	}
	min_distances[0] = 0;
	parent[0] = -1;
	for(j=0; j<n-1; ++j){
		int v = min_distance_vertex_index(min_distances, included_vertex, n);
		included_vertex[v] = true;
		for(i=0; i<n; ++i){
			if( !included_vertex[i] && G[v][i] && G[v][i] < min_distances[i]){
				parent[i] = v;
				min_distances[i] = G[v][i];
			}
		}
	}
	cout<<"Edge \tWeight\n";
	for(i=1; i<n; ++i){
		cout<<parent[i]<<"-"<<i<<"\t"<<G[i][parent[i]]<<endl;
	}

}

int main(){
	int G[10][10], n;
	cout<<"Enter the no. of vertices: ";
	cin>>n;
	cout<<"\nEnter the adjacency matrix: \n";
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin>>G[i][j];
	prims(G, n);
	cout<<endl;
	return 0;
}

/* Enter the no. of vertices: 5

Enter the adjacency matrix: 
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Edge 	Weight
0-1	2
1-2	3
0-3	6
1-4	5
*/