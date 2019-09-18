
import random
from datetime import datetime
import matplotlib.pyplot as plt

def selectionsort(a, n):
	for i in range(n-1):
		min_id = i 
		for j in range(i+1, n):
			if(a[min_id] > a[j]):
				min_id = j
		a[i], a[min_id] = a[min_id], a[i]

def bubblesort(a, n):
	for i in range(n-1):
		flag = False
		for j in range(1, n-i-1):
			if(a[i] > a[j]):
				flag = True
				a[i], a[j] = a[j], a[i]
		if not flag:
			break;

def insertionsort(a, n):
	for i in range(1, n):
		key = a[i]
		j = i-1
		while(j>=0 and a[j]>key):
			a[j+1] = a[j]
			j -= 1
		a[j+1] = key

def merge(a, low, mid, high):
	l = [a[i] for i in range(low, mid+1)]
	r = [a[i] for i in range(mid+1, high+1)]
	n1 = len(l)
	n2 = len(r)
	i, j, k = 0, 0, low
	while(i<n1 and j<n2):
		if l[i]<=r[j] :
			a[k] = l[i]
			i += 1
		else:
			a[k] = r[j]
			j += 1
		k += 1
	while i<n1 :
		a[k] = l[i]
		i += 1
		k += 1
	while j<n2 :
		a[k] = r[j]
		j += 1
		k += 1

def mergesort(a, low, high):
	if(low<high):
		mid = int((low+high)/2)
		mergesort(a, low, mid)
		mergesort(a, mid+1, high)
		merge(a, low, mid, high)

def partition(a, low, high):
	p = a[high]
	i = low-1
	for j in range(low, high):
		if a[j]<=p:
			i += 1
			a[i], a[j] = a[j], a[i]
	a[i+1], a[high] = a[high], a[i+1]
	return i+1

def quicksort(a, low, high):
	if low<high:
		q = partition(a, low, high)
		quicksort(a, low, q-1)
		quicksort(a, q+1, high)


def run():
	random.seed(1010)
	x = []
	y = []
	y1 = []
	y2 = []
	y3 = []
	y4 = []
	for _ in range(5):
		n = int(input("Enter n: "))
		x.append(n)
		a = random.sample(range(1, 1000), n)
		b = random.sample(range(1, 1000), n)
		c = random.sample(range(1, 1000), n)
		d = random.sample(range(1, 1000), n)
		e = random.sample(range(1, 1000), n)
		start = datetime.now()
		mergesort(a, 0, n-1)
		end = datetime.now()
		diff = end - start
		y.append(diff.microseconds)

		start1 = datetime.now()
		quicksort(b, 0, n-1)
		end1 = datetime.now()
		diff1 = end1 - start1
		y1.append(diff1.microseconds)

		start2 = datetime.now()
		selectionsort(c, n)
		end2 = datetime.now()
		diff2 = end2 - start2
		y2.append(diff2.microseconds)

		start3 = datetime.now()
		bubblesort(d, n)
		end3 = datetime.now()
		diff3 = end3 - start3
		y3.append(diff3.microseconds)

		start4 = datetime.now()
		insertionsort(e, n)
		end4 = datetime.now()
		diff4 = end4 - start4
		y4.append(diff4.microseconds)

	plt.xlabel("Number of elements")
	plt.ylabel("Time in microseconds")
	plt.title("Sorting Algorithms")
	plt.scatter(x, y, c='k')
	plt.plot(x, y, 'r', label='Merge sort')
	plt.scatter(x, y1, c='k')
	plt.plot(x, y1, 'b', label='Quick sort')
	plt.scatter(x, y2, c='k')
	plt.plot(x, y2, 'm', label='Selection sort')
	plt.scatter(x, y3, c='k')
	plt.plot(x, y3, 'g', label='Bubble sort')
	plt.scatter(x, y4, c='k')
	plt.plot(x, y4, 'c', label='Insertionsort sort')
	plt.legend()
	plt.show()

if __name__ == '__main__':
	run()