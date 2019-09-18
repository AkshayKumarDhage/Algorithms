#include<bits/stdc++.h>
using namespace std;

void knapsack(int *value, int *weight, int n, int capacity){
	int k[n+1][capacity+1];

	for(int i=0;i<=n;++i){
		for(int j=0;j<=capacity;++j){

			if(i==0 || j==0)
				k[i][j] = 0;
			else if(weight[i-1] <= j)
				k[i][j] = max(value[i-1] + k[i-1][j-weight[i-1]], k[i-1][j]);
			else
				k[i][j] = k[i-1][j];
		}
	}

	cout<<"Max profit: "<<k[n][capacity]<<endl;
}

int main(){
	int value[10], weight[10], n, capacity;
	cout<<"Enter n: ";
	cin>>n;
	cout<<"Enter item value and weight:\n";
	for(int i=0;i<n;++i)
		cin>>value[i]>>weight[i];

	cout<<"Enter the capacity: ";
	cin>>capacity;

	knapsack(value, weight, n, capacity);
	return 0;
}

/*Enter n: 3
Enter item value and weight:
60 10 
100 20
120 30
Enter the capacity: 50
Max profit: 220
 */