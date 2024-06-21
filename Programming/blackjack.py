suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')
values = {'Two':2, 'Three':3, 'Four':4, 'Five':5, 'Six':6, 'Seven':7, 'Eight':8, 
            'Nine':9, 'Ten':10, 'Jack':10, 'Queen':10, 'King':10, 'Ace':11}
class Bank:
	def __init__(self,holder_name,balance=0):
		self.balance=balance
		self.holder_name=holder_name
	def credit(self, amount):
		self.amount=amount
		self.balance+=self.amount
		print(f"{self.holder_name} is credited with {self.amount} and now the balance is {self.balance}")
	def debit(self, amount):
		self.amount=amount
		self.balance-=self.amount
		print(f"{self.holder_name} is debited with {self.amount} and now the balance is {self.balance}")
	
	

def check_burst(sum):
	if sum>21:
		return True
	else:
		return False



import random
class Player:
	def __init__(self,name, cards_dealt):
		self.name=name
		self.inhand=cards_dealt
		
	def play(self,sum1):
		self.sum=sum1
		while True:
			print(f"Current sum is {self.sum}")
			check=input("Do you want to hit or stay? ").lower()
			if check=='hit':
				self.inhand.append(new_deck.draw_card())
				self.sum+=values[self.inhand[-1].rank]
				print(f'Player drew {self.inhand[-1]} and now the sum is {self.sum}')
				if check_burst(self.sum):
					return 0
				else:
					pass
			elif check=='stay':
				return self.sum
			else:
				print("Please enter hit or stay")
				continue






class Dealer:
	def __init__(self,cards_dealt):
		self.inhand=cards_dealt
	
	def play(self,sum1):
		self.sum=sum1

		while player.sum>=self.sum:
			self.inhand.append(new_deck.draw_card())
			self.sum+=values[self.inhand[-1].rank]
			print(f'Dealer drew {self.inhand[-1]} and now the sum is {self.sum}')
			if check_burst(self.sum):
				return 0
			else:
				pass
		return self.sum

	

class Deck:
	def __init__(self):
		self.all_cards=[]
		for suit in suits:
			for rank in ranks:
				self.all_cards.append(Card(rank,suit))
	def shuffle_deck(self):
		random.shuffle(self.all_cards)

	def draw_card(self):
		return self.all_cards.pop(0)


class Card():
	def __init__(self, rank, suit):
		self.rank=rank
		self.suit=suit
		self.value=values[self.rank]

	def __str__(self):
		return self.rank+ ' of ' +self.suit


def current_state(player, dealer):
	print("Player has cards: ")
	for cards in player:
		print(cards)
	print("Dealer has cards: ")
	for dcards in dealer:
		print(dcards)

print("WELCOME TO BLACKJACK!")
name=input("Enter your name: ")
new_deck=Deck()
new_deck.shuffle_deck()
player_acc=Bank(name,int(input('How much money do you have? ')))
pot=Bank('Pot')
bet=int(input('Place your bet: '))
player_acc.debit(bet)
pot.credit(bet)

print("We will begin now by dealing the initial cards")
player_cards=[]
dealer_cards=[]
for cards in range(2):
	player_cards.append(new_deck.draw_card())
	dealer_cards.append(new_deck.draw_card())
player=Player(name,player_cards)
dealer=Dealer(dealer_cards)
print(f'The dealer has card {dealer_cards[0]} and a blind one')
print(f'The player has cards {player_cards[0]} and {player_cards[1]}')
sump=player_cards[0].value + player_cards[1].value
sumd=dealer_cards[0].value + dealer_cards[1].value

x=player.play(sump)

if x==0:
	print("Dealer wins.YOU HAVE BURST!!")
	pot.debit(pot.balance)
else:
	y=dealer.play(sumd)
	if y==0:
		print("YOU win.DEALER HAS BURST!!")
		pot.debit(pot.balance)

	elif x>y:
		print("Player wins")
		player_acc.credit(2*(pot.balance))

	elif y>x:
		print("Dealer wins")
		pot.debit(pot.balance)
	else:
		print("No one wins. ITS A DRAW!")
		pot.debit(pot.balance)
		player_acc.credit(pot.balance)





















