import copy
import time
def columnRow(mat,b,c):
	'''
	for checking column row attacked points
	'''
	for x in range(0,8):
		if not(x==c):
			mat[b][x]+=100
	for y in range(0,8):
		if not(y==b):

			mat[y][c]+=100
	return (mat)





def diagonal(mat,b,c):
	'''
	for checking diagonal attack points
	'''
	col=b 
	row=c
	try:
		while (col+1<=7) and (row+1<=7) and (col+1>=0) and (row+1>=0):
			mat[col+1][row+1]+=100
			col+=1
			row+=1
	except:
		pass
	col=b 
	row=c
	try:
		while  (col+1<=7) and (row-1<=7) and (col+1>=0) and (row-1>=0):
			mat[col+1][row-1]+=100
			col+=1
			row-=1
	except:
		pass
	col=b 
	row=c
	try:
		while  (col-1<=7) and (row+1<=7) and (col-1>=0) and (row+1>=0):
			mat[col-1][row+1]+=100
			col-=1
			row+=1
	except:
		pass
	col=b 
	row=c

	try:
		while  (col-1<=7) and (row-1<=7) and (col-1>=0) and (row-1>=0):
			mat[col-1][row-1]+=100
			col-=1
			row-=1
	except:
		pass
	return (mat)




def printIndex(mat):

	'''for printing all final queen places'''

	for x in range(0,8):
		for y in range(0,8):
			if mat[x][y]==0:
				print('a {}{}'.format(x,y))


	


def checkIteration(mat):
	'''checks matrix passed for whether it satisfies the 8 queen problem statement '''
	matrix=copy.deepcopy(mat)
	
	for x in range(0,8):
		for y in range(0,8):
			if ((matrix[y][x])%100)==1:
				matrix=markBoard(matrix,y,x)
	
	for i in range(0,8):
		for j in range(0,8):
			if (matrix[i][j]%100!=0) and (matrix[i][j]/100>=1):
				return False
	return True
			



def markBoard(mat,x,y):

	mat=columnRow(mat,x,y)
	mat=diagonal(mat,x,y)
	return mat
st=time.time()
			
a=[[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0]]

number_of_solutions = 0


	

for col1 in range(0,8):
	a[0][col1]=1
	for col2 in range(0,8):
		a[1][col2]=1
		if checkIteration(a):

			for col3 in range(0,8):
				a[2][col3]=1
				if checkIteration(a):

					for col4 in range(0,8):
						a[3][col4]=1
						if checkIteration(a):

							for col5 in range(0,8):
								a[4][col5]=1
								if checkIteration(a):

									for col6 in range(0,8):
										a[5][col6]=1
										if checkIteration(a):
											for col7 in range(0,8):
												a[6][col7]=1
												if checkIteration(a):

													for col8 in range(0,8):
														'''iterating through all possible combitions of 8 queens, one column at a time'''
														a[7][col8]=1
														'''checking this iteration of board and adding to number of solutions'''
														


														if checkIteration(a):
															number_of_solutions += 1
															

														
										

														a[7]=[0,0,0,0,0,0,0,0]
												a[6]=[0,0,0,0,0,0,0,0]
										a[5]=[0,0,0,0,0,0,0,0]
								a[4]=[0,0,0,0,0,0,0,0]
						a[3]=[0,0,0,0,0,0,0,0]
				a[2]=[0,0,0,0,0,0,0,0]
		a[1]=[0,0,0,0,0,0,0,0]
	a[0]=[0,0,0,0,0,0,0,0]
	
print("Number of solutions are {}".format(number_of_solutions))

et=time.time()
print(et-st)









