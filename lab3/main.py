import pygame as g
from pygame.draw import *
g.init()
screen = g.display.set_mode((300,200))
g.display.update()
clock = g.time.Clock()


while True:
    clock.tick(30)
    for event in g.event.get():
        if event.type == g.QUIT:
            g.quit()