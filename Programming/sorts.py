#selection sort

def selection_sort(lst):



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
