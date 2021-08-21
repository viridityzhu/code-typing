import random
class Dutu:
    def __init__(self):
        self.total=1000000
        self.cash=0
        self.lose = 0
        self.rent=0
    def play_game(self):
        self.cash+=20000
        self.total-=20000
    def check_lose(self):
        self.lose+=1
        self.cash-=20000
    def check_win(self):
        self.cash+=20000
    def check_big(self):
        if self.lose==3:
            self.lose=0
            return True
    def play_big(self):
        self.total -= self.cash * 0.5
        self.cash*=1.5
    def rent_high(self):
        self.total=20000
        self.rent=1
    def return_high(self):
        self.total-=40000
        self.rent=0
du=Dutu()
while True:
    du.play_game()
    a=random.randint(0,1)
    if a==0:
        du.check_lose()
        if du.check_big():
            du.play_big()
    elif a==1:
        du.check_win()
    if du.rent == 1:
        du.return_high()
    if du.total==0and du.cash==0:
        du.rent_high()

    print('He now has {}, rent {}'.format(du.total,du.rent))
    if du.total<-500000:
        break