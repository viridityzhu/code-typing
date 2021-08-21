import pygame
from sys import exit
from random import randint


class Rick:
    def restart(self):
        self.x = 1000
        self.y = 300

    def __init__(self):
        self.restart()
        self.image=pygame.image.load('ricks head.png').convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.top = self.y
        self.rect.left = self.x
    def move(self):
        x, y = pygame.mouse.get_pos()
        x -= self.image.get_width() / 2
        y -= self.image.get_height() / 2
        self.x = x
        self.y = y
        self.rect.top = self.y
        self.rect.left = self.x

class Mortyhead:
    def restart(self):
        x, y = pygame.mouse.get_pos()
        self.x = x - self.image.get_width() / 2
        self.y = y - self.image.get_height() / 2
        self.rect.top = self.y
        self.rect.left = self.x
        self.active=True
    def __init__(self):
        self.x=-100
        self.y=0
        self.image=pygame.image.load('morty head.png').convert_alpha()
        self.active=False
        self.rect = self.image.get_rect()
        self.rect.top = self.y
        self.rect.left=self.x
    def move(self):
        self.x -= 40
        self.rect.top = self.y
        self.rect.left = self.x
        if self.x<0:
            self.active=False
class Enemy:
    def restart(self):
        self.x=randint(0,50)
        self.y=randint(0,600)
        self.speed=randint(10,30)

    def __init__(self):
        self.restart()
        self.image=pygame.image.load('enemy.png').convert_alpha()
        self.rect=self.image.get_rect()
        self.rect.top = self.y
        self.rect.left = self.x
    def move(self):
        if self.x>1200:
            self.restart()
        else:
            self.x+=self.speed
            self.rect.top = self.y
            self.rect.left = self.x
def CheckHit(morty,enemy):
    mxl=morty.x

    myu=morty.y
    myd=morty.y+morty.image.get_height()

    exr=enemy.x+enemy.image.get_width()
    eyu=enemy.y
    eyd=enemy.y+enemy.image.get_height()
    if mxl<exr and  ((myd>eyu and myd<eyd) or (myu<eyd and myu>eyu)):
        morty.active=False

        enemy.restart()
        return True
    else:
        return False


# def CheckCrash(rick,enemy):
#     mxl=rick.x
#     mxr=rick.x+rick.image.get_width()
#     myu=rick.y
#     myd=rick.y+rick.image.get_height()
#     exl=enemy.x
#     exr=enemy.x+enemy.image.get_width()
#     eyu=enemy.y
#     eyd=enemy.y+enemy.image.get_height()
#     #((mxl<exr and mxl>exl) or (mxr<exr and mxr>exl)) and  ((myd>eyu and myd<eyd) or (myu<eyd and myu>eyu))
#
#     if pygame.sprite.collide_mask(rick,enemy):
#         return True
#     else:
#         return False

pygame.init()
screen = pygame.display.set_mode((1200, 710), 0, 32)
pygame.display.set_caption("Rick v.s. 白脸怪")
background2 = pygame.image.load('bg2.jpg')
mortyheads = []
enemies = []
for i in range(5):
    mortyheads.append(Mortyhead())

for i in range(3):
    enemies.append(Enemy())
count_m = len(mortyheads)
index_m = 0
interval_m = 0
rickhead = Rick()

score = 0
gameover = False
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
    screen.blit(background2, (0, 0))
    if not gameover:
        font = pygame.font.Font(None, 32)
        text = font.render("Score:%d" % score, 1, (0, 0, 0))
        screen.blit(text, (0, 0))
        interval_m -= 1
        if interval_m < 0:
            mortyheads[index_m].restart()
            interval_m = 8
            index_m = (index_m + 1) % count_m  # amazing!!!
        for i in mortyheads:
            if i.active:
                i.move()
                screen.blit(i.image, (i.x, i.y))
                for b in enemies:
                    if CheckHit(i, b):
                        score += 100
        screen.blit(rickhead.image, (rickhead.x, rickhead.y))
        rickhead.move()
        for e in enemies:
            e.move()
            screen.blit(e.image, (e.x, e.y))
            #gameover = CheckCrash(rickhead, e)
        gameover=pygame.sprite.spritecollide(rickhead,enemies,0)
    else:
        font = pygame.font.Font(None, 100)
        text = font.render("Score:%d" % score, 1, (0, 0, 0))

        screen.blit(text, (460, 300))
    if gameover and event.type==pygame.MOUSEBUTTONUP:
        rickhead.restart()
        score=0
        for e in enemies:
            e.restart()
        for i in mortyheads:
            i.active=False
        gameover=False
    pygame.display.update()