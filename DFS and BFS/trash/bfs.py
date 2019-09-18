from collections import deque

def BFS(graph, n):
	visited = [0 for _ in range(n)]
	v = int(input("Enter vertex: "))
	i = v
	queue = deque([])
	print("Graph is: ")
	bfs(graph, i, n, visited, queue)
	i = (i + 1)%n
	while i!=v:
		bfs(graph, i, n, visited, queue)
		i = (i + 1)%n

def bfs(graph, v, n, visited, queue):
	if visited[v]!=1:
		queue.append(v)
		visited[v]=1
		while len(queue):
			top = queue[0]
			print(top, end='\t')
			queue.popleft()
			for i in range(n):
				if visited[i]==0 and graph[top][i]==1:
					queue.append(i)
					visited[i] = 1

def main():
	n = int(input("Enter n: "))
	graph = [0 for _ in range(n)]
	print("Enter graph: ")
	for i in range(n):
		graph[i] = list(map(int, input().split()))
	BFS(graph, n)
	print('\n')

if __name__ == '__main__':
	main()