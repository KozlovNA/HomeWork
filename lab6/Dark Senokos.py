import math
from random import *
import pygame
import numpy as np

FPS = 30

WIDTH = 800
HEIGHT = 600

LEFT = 1
RIGHT = 2
DOWN = 3
UP = 4
STOP = 0
motion = 0
timer = 0
points = 0

C = pygame.image.load('C++.png')
C.set_colorkey((255, 255, 255))
Pyton = pygame.image.load('pyton.png')
Pyton.set_colorkey((255, 255, 255))
VisualStudio = pygame.image.load('VS.png')
VisualStudio.set_colorkey((255, 255, 255))

Sprites = [C, Pyton, VisualStudio]
pygame.mixer.init()

hitsound = pygame.mixer.Sound('hit.wav')

pygame.font.init()
screen = pygame.display.set_mode((640, 480))
font = pygame.font.Font(pygame.font.get_default_font(), 36)

class Proga:
    def __init__(self, screen: pygame.Surface, x=40, y=450):
        """ Конструктор класса proga

        Args:
        x - начальное положение проги по горизонтали
        y - начальное положение проги по вертикали
        """
        self.screen = screen
        self.x = x
        self.y = y
        self.r = 50
        self.vx = 0
        self.vy = 0
        self.g = -3
        self.timer = 300
        self.surf = pygame.transform.scale(choice(Sprites), (self.r, self.r))

    def move(self):
        """Переместить прогу по прошествии единицы времени.

        Метод описывает перемещение проги за один кадр перерисовки. То есть, обновляет значения
        self.x и self.y с учетом скоростей self.vx и self.vy, силы гравитации, действующей на прогу,
        и стен по краям окна (размер окна 800х600).
        """
        self.x += self.vx
        self.y -= self.vy
        self.vy += self.g
        self.timer -= 1
        if self.x < 0:
            self.vx = (-self.vx) * 0.8
            self.x = 1
        elif self.x + self.r > 800:
            self.vx = (-self.vx) * 0.8
            self.x = 800 - self.r
        if self.y < 0:
            self.vy = -self.vy
            self.y = 1
        elif self.y + self.r > 600:
            self.vy = (-self.vy) * 0.8 + self.g
            self.y = 600 - self.r

    def draw(self):
        self.r = randint(50, 75)
        screen.blit(self.surf, (self.x, self.y))

    def hittest(self, obj):
        """Функция проверяет сталкивалкивается ли Дим с прогой.
        Args:
            obj: Дим
        Returns:
            Возвращает True в случае столкновения Дима и проги. В противном случае возвращает False.
        """
        return (abs(obj.x - self.x) < max(self.r, obj.r) and (abs(obj.y - self.y) < max(self.r, obj.r)))

class Gun:
    def __init__(self, screen):
        self.screen = screen
        self.puska = pygame.Surface((75, 75), pygame.SRCALPHA)
        self.f2_power = 10
        self.f2_on = 0
        self.an = 1
        self.x = 40
        self.y = 450

    def fire2_start(self, event):
        self.f2_on = 1

    def fire2_end(self, event):
        """Выстрел мячом.

        Происходит при отпускании кнопки мыши.
        Начальные значения компонент скорости мяча vx и vy зависят от положения мыши.
        """
        global balls, bullet
        bullet += 1
        new_proga = Proga(self.screen, self.x, self.y)
        self.an = math.atan2((event.pos[1]-self.y), (event.pos[0]-self.x))
        new_proga.vx = self.f2_power * math.cos(self.an)
        new_proga.vy = - self.f2_power * math.sin(self.an)
        progi.append(new_proga)
        self.f2_on = 0
        self.f2_power = 10

    def targetting(self, event):
        """Прицеливание. Зависит от положения мыши."""
        if event:
            self.an = math.atan2((event.pos[1]-self.y), (event.pos[0]-self.x))

    def draw(self):
        self.senokos = pygame.image.load('Dark_senokos.png')
        screen.blit(pygame.transform.scale(self.senokos, (75, 75)), (self.x, self.y))

    def power_up(self):
        if self.f2_on:
            if self.f2_power < 100:
                self.f2_power += 1


class Target():

    def __init__(self, screen: pygame.Surface):
        """ Инициализация новой цели. """
        self.screen = pygame.Surface((75, 75), pygame.SRCALPHA)
        self.x = randint(20, 780)
        self.y = randint(50, 400)
        self.r = randint(75, 100)
        self.points = 0
        self.live = 1
        self.vx = randint(-2, 2)
        self.vy = randint(-2, 2)


    def hit(self, points=1):
        """Попадание шарика в цель."""
        self.screen = pygame.Surface((75, 75), pygame.SRCALPHA)
        self.x = randint(20, 780)
        self.y = randint(50, 550)
        self.r = randint(75, 100)
        self.live = 1
        self.vx = randint(-2, 2)
        self.vy = randint(-2, 2)


    def move(self):
        self.x += self.vx
        self.y -= self.vy
        if self.x < 0:
            self.vx = -self.vx
            self.x = 1
        elif self.x + self.r > 800:
            self.vx = -self.vx
            self.x = 800 - self.r
        if self.y < 0:
            self.vy = -self.vy
            self.y = 1
        elif self.y + self.r > 600:
            self.vy = -self.vy
            self.y = 600 - self.r

    def draw(self):
        self.Safin = pygame.image.load('Dim_Dimych.png')
        screen.blit(pygame.transform.scale(self.Safin, (self.r, self.r)), (self.x, self.y))

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
bullet = 0
progi = []
targets = []

pygame.mixer.music.load('zhopa.mp3')
pygame.mixer.music.play()

for t in range(4):
    targets.append(Target(screen))

clock = pygame.time.Clock()
gun = Gun(screen)
finished = False

while not finished:
    bg = pygame.image.load('background.jpg')
    screen.blit(pygame.transform.scale(bg, (800, 600)), (0, 0))
    gun.draw()
    text_surface = font.render('Отчислено: ' + str(points), True, (0, 0, 0))
    screen.blit(text_surface, (0, 0))
    timer += 1

    for b in progi:
        b.draw()
    for t in targets:
        t.draw()
    pygame.display.update()

    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True
        elif event.type == pygame.MOUSEBUTTONDOWN:
            gun.fire2_start(event)
        elif event.type == pygame.MOUSEBUTTONUP:
            gun.fire2_end(event)
        elif event.type == pygame.MOUSEMOTION:
            gun.targetting(event)
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_a:
                motion = LEFT
            elif event.key == pygame.K_d:
                motion = RIGHT
            elif event.key == pygame.K_w:
                motion = UP
            elif event.key == pygame.K_s:
                motion = DOWN
        elif event.type == pygame.KEYUP:
            if event.key in [pygame.K_a, pygame.K_d, pygame.K_w, pygame.K_s]:
                motion = STOP
    if motion == LEFT:
        gun.x -= 3
    elif motion == RIGHT:
        gun.x += 3
    elif motion == UP:
        gun.y -= 3
    elif motion == DOWN:
        gun.y += 3

    for b in progi:
        b.move()
        if b.timer <= 0:
            progi.remove(b)
        for target in targets:
            if b.hittest(target) and target.live:
                target.live = 0
                target.hit()
                points += 1
                hitsound.play()




    for t in targets:
        t.move()

    gun.power_up()

pygame.quit()