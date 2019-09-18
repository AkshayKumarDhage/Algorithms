
import random
import matplotlib.pyplot as plt

def lsearch(a, key):
	c = 0
	for i in a:
		c += 1
		if(key==i):
			return c
	return c

def bsearch(a, key):
	low, high = 0, len(a)-1
	c = 0
	while(low<=high):
		c += 1
		mid = (low + high)//2
		if(a[mid]==key):
			return c
		elif a[mid]>key:
			high = mid-1
		else:
			low = mid+1
	return c

def interpolationsearch(a, key):
	low, high = 0, len(a)-1
	c = 0
	while(low<high):
		pos = low + int((float(high-low)/(a[high]-a[low])) * (key - a[low]))
		c += 1
		if(a[pos]==key):
			return c
		elif a[pos]>key:
			high = pos-1
		else:
			low = pos+1
	return c

def run():
	random.seed(1010)
	x = []
	y1 = []
	y2 = []
	y3 = []
	for i in range(5):
		n = int(input("Enter n: "))
		x.append(n)
		a = [2*k+2 for k in range(0, n)]
		print(a)
		key = int(input("Enter key: "))
		#c1 = lsearch(a, key)
		print(a)
		#c2 = bsearch(a, key)
		c3 = interpolationsearch(a, key)
		'''y1.append(c1)
		y2.append(c2)'''
		y3.append(c3)
	#plt.title("Linear Search vs Binary Search")
	plt.title("Interpolation Search")
	plt.xlabel("Number of elements")
	plt.ylabel("Number of comparisions")
	'''plt.scatter(x, y1, c='k')
	plt.scatter(x, y2, c='k')'''
	plt.scatter(x, y3, c='k')
	'''plt.plot(x, y1, 'r', label='Linear Search')
	plt.plot(x, y2, 'm--', label='Binary Search')'''
	plt.plot(x, y3, 'b', label='Interpolation Search')
	plt.legend()
	plt.show()


if __name__ == '__main__':
	run()