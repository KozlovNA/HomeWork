import pygame
import pygame.draw
from pygame.draw import *

pygame.init()

FPS = 30
screen = pygame.display.set_mode((500, 500))

#code
pygame.draw.circle(screen, (255, 255, 0), (250, 250), 100, 0)
pygame.draw.circle(screen, (255, 0, 0), (200, 220), 30, 0)
pygame.draw.circle(screen, (255, 0, 0), (300, 220), 30, 0)
rect(screen, (0, 0, 0), (200, 275, 100, 20), 0)
pygame.draw.circle(screen, (0, 0, 0), (200, 220), 10, 0)
pygame.draw.circle(screen, (0, 0, 0), (300, 220), 10, 0)
polygon(screen, (0, 0, 0), [(256,206), (270,220),
                               (305,195), (291,171)], 0)
polygon(screen, (0, 0, 0), [(244,206), (230,220),
                               (195,195), (209,171)], 0)
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
