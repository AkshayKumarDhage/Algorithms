#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
	int source, dest, weight;
};

bool compare(Edge e1, Edge e2){
	return e1.weight < e2.weight;
}

int find_parent(int curr, int *parent){
	if(parent[curr] == curr)
		return curr;
	return find_parent(parent[curr], parent);
}

void kruskal(Edge *input_edges, int n, int e){
	sort(input_edges, input_edges+e, compare);

	Edge *output = new Edge[n-1];

	int count=0, *parent= new int[n];

	for(int i=0;i<n;++i){
		parent[i] = i;
	}

	int i=0;
	while(count != n-1){
		Edge current_edge = input_edges[i];

		int source_parent = find_parent(current_edge.source, parent);
		int dest_parent = find_parent(current_edge.dest, parent);

		if(source_parent != dest_parent){
			output[count] = current_edge;
			parent[source_parent] = dest_parent;
			count++;
		}
		i++;
	}
	cout<<"Source - Dest"<<"\t"<<"Weight"<<endl;
	for(int j=0;j<n-1;++j){
		cout<<"     "<<output[j].source<<" - "<<output[j].dest<<"  \t"<<output[j].weight<<endl;
	}
}

int main(){
	int a[10][10], n, e;
	cout<<"Enter no. of vertices and edgess: ";
	cin>>n>>e;
	cout<<"Enter weighted matrix: "<<endl;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}
	Edge *input_edges = new Edge[e];
	int count = 0;
	for(int i=0;i<n;++i){
		for(int j=i;j<n;++j){
			if(a[i][j] != 0 && count!=e){
				input_edges[count].source = i;
				input_edges[count].dest = j;
				input_edges[count].weight = a[i][j];
				count++;
			}
		}
	}
	kruskal(input_edges, n, e);
	return 0;
}

/*Enter no. of vertices and edgess: 4 5
Enter weighted matrix: 
0 10 6 5
10 0 0 15
6 0 0 4
5 15 4 0
Source - Dest	Weight
     2 - 3  	4
     0 - 3  	5
     0 - 1  	10


	   10
   0-------1
   | \	   |
 6 |  5\   |15
   |     \ |
   2-------3
       4
*/

/*Enter no. of vertices and edgess: 9 14
Enter weighted matrix: 
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0 
0 0 0 9 0 10 0 0 0 
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6 
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
Source - Dest	Weight
     6 - 7  	1
     2 - 8  	2
     5 - 6  	2
     0 - 1  	4
     2 - 5  	4
     2 - 3  	7
     0 - 7  	8
     3 - 4  	9
*/