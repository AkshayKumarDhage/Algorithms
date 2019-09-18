
def DFS(graph, n):
	visited = [0 for _ in range(n)]
	v = int(input("Enter starting vertex: "))
	i = v
	print('DFS graph is: ')
	dfs(graph, i, n, visited)
	i = (i + 1)%n
	while i!=v:
		dfs(graph, i, n, visited)
		i = (i + 1)%n

def dfs(graph, v, n, visited):
	if visited[v]!=1:
		print(v, end="\t")
		visited[v] = 1
		for i in range(0,n):
			if visited[i]==0 and graph[v][i]==1:
				dfs(graph, i, n, visited)

def main():
	n = int(input("Enter n: "))
	graph = [0 for _ in range(n)]
	print("Enter graph: ")
	for i in range(n):
		graph[i] = list(map(int, input().split()))
	DFS(graph,n)

if __name__ == '__main__':
	main()