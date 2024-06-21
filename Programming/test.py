from IPython.display import clear_output
def display_board(board):
	clear_output()

	print(f" {board[7]} | {board[8]} | {board[9]} ")
	print("-----------")
	print(f" {board[4]} | {board[5]} | {board[6]} ")
	print("-----------")
	print(f" {board[1]} | {board[2]} | {board[3]} ")

def check_board(board, x):
	if board[x]!= ' ':
		return False
	else:
		return True

def check_win(board):
	if (board[1]==board[2]==board[3]=='X' or board[4]==board[5]==board[6]=='X' or board[7]==board[8]==board[9]=='X' or board[7]==board[5]==board[3]=='X' or board[1]==board[5]==board[9]=='X' or board[7]==board[4]==board[1]=='X' or board[8]==board[5]==board[2]=='X' or board[9]==board[6]==board[3]=='X' or board[1]==board[2]==board[3]=='O' or board[4]==board[5]==board[6]=='O' or board[7]==board[8]==board[9]=='O' or board[7]==board[5]==board[3]=='O' or board[1]==board[5]==board[9]=='O' or board[7]==board[4]==board[1]=='O' or board[8]==board[5]==board[2]=='O' or board[9]==board[6]==board[3]=='O'):
		return True
	else:
		return False 





def play_game(board, char, char0):

	x=int(input("Enter place: "))
	if check_board(board, x):
		board[x]=char
		display_board(board)
		if check_win(board):
			end_game(board)
		else:
			play_game(board, char0, char)
	else:
		print("Wrong input. Try again")
		play_game(board,char,char0)
	



def choosing_marker():
	marker=' '
	marker0=' '
	while marker != "X" and marker!="O":
		marker=input("Enter player 1 marker: ")
	if marker=='X':
		marker0='O'
	else:
		marker0='X'
	return (marker,marker0)




def end_game(board):
	print("CONGRATULATIONS YOU HAVE WON!")
	x=' '
	while x!='Y' and x!='N':

		x=input("Do you want to play again?(Y or N): ")
		if x!='Y' and x!='N':
			print("Please enter Y or N only")
		elif x=='Y':
			start_game()
		else:
			pass



def start_game():
	board=['#',' ',' ',' ',' ',' ',' ',' ',' ',' ']
	print("Welcome to TIC TAC TOE!!")
	display_board(board)
	x,y= choosing_marker()
	play_game(board,x,y)

start_game()








	
