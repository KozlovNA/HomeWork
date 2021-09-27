import pygame
import pygame.draw
from pygame.draw import *

pygame.init()

FPS = 30
screen = pygame.display.set_mode((500, 500))

#code
rect(screen, (66, 170, 255), (0, 0, 500, 250), 0)  # sky
rect(screen, (0, 128, 0), (0, 250, 500, 250), 0)  # grass
rect(screen, (150, 75, 0), (100, 200, 150, 100), 0)  # house
polygon(screen, (255, 0, 0), [(175, 125), (100, 200), (250, 200)], 0)  # roof
rect(screen, (150, 75, 0), (350, 220, 15, 60), 0)  # log


#code

pygame.display.update()
clock = pygame.time.Clock()
finished = False

while not finished:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True

pygame.quit()