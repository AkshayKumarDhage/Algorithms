
import random
import matplotlib.pyplot as plt

global count1, count2, count3, count4, count5, count6

#O(n^2)
def selectionsort(a, n):
	global count1
	for i in range(n-1):
		min_id = i 
		for j in range(i+1, n):
			if(a[min_id] > a[j]):
				count1 += 1
				min_id = j
		a[i], a[min_id] = a[min_id], a[i]

#O(n^2)  omega(n)
def bubblesort(a, n):
	global count2
	for i in range(n-1):
		flag = False
		for j in range(0, n-i-1):
			if(a[j] > a[j+1]):
				count2 += 1
				flag = True
				a[j], a[j+1] = a[j+1], a[j]
		if not flag:
			break;

#O(n^2)
def insertionsort(a, n):
	global count3
	for i in range(1, n):
		key = a[i]
		j = i-1
		while(j>=0 and a[j]>key):
			count3 += 1
			a[j+1] = a[j]
			j -= 1
		a[j+1] = key

#O(nlogn)
def merge(a, low, mid, high):
	global count4
	l = [a[i] for i in range(low, mid+1)]
	r = [a[i] for i in range(mid+1, high+1)]
	n1 = len(l)
	n2 = len(r)
	i, j, k = 0, 0, low
	while(i<n1 and j<n2):
		count4 += 1
		if l[i]<=r[j] :
			a[k] = l[i]
			i += 1
		else:
			a[k] = r[j]
			j += 1
		k += 1
	while i<n1 :
		count4 += 1
		a[k] = l[i]
		i += 1
		k += 1
	while j<n2 :
		count4 += 1
		a[k] = r[j]
		j += 1
		k += 1

def mergesort(a, low, high):
	if(low<high):
		mid = int((low+high)/2)
		mergesort(a, low, mid)
		mergesort(a, mid+1, high)
		merge(a, low, mid, high)

#O(nlogn)
def partition(a, low, high):
	global count5
	p = a[high]
	i = low-1
	for j in range(low, high):
		if a[j]<=p:
			count5 += 1
			i += 1
			a[i], a[j] = a[j], a[i]
	a[i+1], a[high] = a[high], a[i+1]
	return i+1

def quicksort(a, low, high):
	if low<high:
		q = partition(a, low, high)
		quicksort(a, low, q-1)
		quicksort(a, q+1, high)

#O(nlogn)
def heapify(a, n, i):
	global count6 
	largest = i 
	l = 2*i + 1
	r = 2*i + 2 
	if l<n and a[l]>a[largest]:
		count6 += 1
		largest = l
	if r<n and a[r]>a[largest]:
		count6 += 1
		largest = r
	if largest!=i:
		a[i], a[largest] = a[largest], a[i]
		heapify(a, n, largest)

def heapsort(a):
	n = len(a)
	for i in range(n//2-1, -1, -1):
		heapify(a, n, i)
	for i in range(n-1, -1, -1):
		a[0], a[i] = a[i], a[0]
		heapify(a, i, 0)


def run():
	global count1, count2, count3, count4, count5, count6
	random.seed(1010)
	x, y1, y2, y3, y4, y5, y6 = [], [], [], [], [], [], []
	for _ in range(5):
		n = int(input("Enter n: "))
		a = random.sample(range(1, 100000), n)
		b = random.sample(range(1, 100000), n)
		c = random.sample(range(1, 100000), n)
		d = random.sample(range(1, 100000), n)
		e = random.sample(range(1, 100000), n)
		f = random.sample(range(1, 100000), n)
		count1 = count2 = count3 = count4 = count5 = count6 = 0
		selectionsort(a, n)
		bubblesort(b, n)
		insertionsort(c, n)
		quicksort(d, 0, n-1)
		mergesort(e, 0, n-1)
		heapsort(f)
		x.append(n)
		y1.append(count1)
		y2.append(count2)
		y3.append(count3)
		y4.append(count4)
		y5.append(count5)
		y6.append(count6)
	plt.title("Sorting Algorithms")
	plt.xlabel("No. of elements")
	plt.ylabel("No. of comparisions")
	plt.scatter(x,y1,c='k')
	plt.scatter(x,y2,c='k')
	plt.scatter(x,y3,c='k')
	plt.scatter(x,y4,c='k')
	plt.scatter(x,y5,c='k')
	plt.scatter(x,y6,c='k')
	plt.plot(x,y1,'b', label='selectionsort')
	plt.plot(x,y2,'m--', label='bubblesort')
	plt.plot(x,y3,'r', label='insertionsort')
	plt.plot(x,y4,'g--', label='quicksort')
	plt.plot(x,y5,'c', label='mergesort')
	plt.plot(x,y6,'y', label='heapsort')
	plt.legend()
	plt.show()

if __name__ == '__main__':
	run()