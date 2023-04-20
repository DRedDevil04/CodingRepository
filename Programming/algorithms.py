#selection sort

def selectionSort(lst):



	for n in range(0,len(lst)):
		mini=lst[n]
		x=0

		for index in range(n,len(lst)):
			if lst[index]<mini:
				mini=lst[index]
				ind=index
				x=1
				
			else:
				pass
		if x==1:

			lst[ind]=lst[n]
			lst[n]=mini

		else :
			pass

	return lst
def mergeSort(lst):
	pass



def insertionSort(lst):
	pass


def binary_search(lst,x):
	if lst[int((len(lst)-1)/2)]==x:
		return True
	elif len(lst)==1:
		return False
	else:
		if lst[int((len(lst)-1)/2)]>=x:
			binary_search(lst[0:int((len(lst)-1)/2)-1],x)
		else:
			binary_search(lst[int((len(lst)-1)/2)+1:],x)




