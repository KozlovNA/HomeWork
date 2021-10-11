import pygame
from pygame.draw import *
from random import randint
pygame.init()

FPS = 0.5
screen = pygame.display.set_mode((1200, 900))

RED = (255, 0, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)
GREEN = (0, 255, 0)
MAGENTA = (255, 0, 255)
CYAN = (0, 255, 255)
BLACK = (0, 0, 0)
COLORS = [RED, BLUE, YELLOW, GREEN, MAGENTA, CYAN]
i = 0

def new_ball():
    """
    создает новый шарик
    """
    global x, y, r
    x = randint(100, 1100)
    y = randint(100, 900)
    r = randint(10, 100)
    color = COLORS[randint(0, 5)]
    circle(screen, color, (x, y), r)

def is_inside(mouse_x, mouse_y):
    """
returs True if cursor is inside the ball
    :param mouse_x: cursor x coordinate
    :param mouse_y: cursor y coordinate
    :return:
    """
    return (x - mouse_x) ** 2 + (y - mouse_y) ** 2 < r ** 2


def click(event):
    """
    links checking cursor position with event
    """
    (mouse_x, mouse_y) = event.pos
    return is_inside(mouse_x, mouse_y)




pygame.display.update()
clock = pygame.time.Clock()
finished = False

while not finished:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True
        elif event.type == pygame.MOUSEBUTTONDOWN:
            print('Click!')
            if click(event) == True:
                print('nice cock')
                i += 1
                print('cock size: ', i, 'cm')

    new_ball()
    pygame.display.update()
    screen.fill(BLACK)

pygame.quit()
