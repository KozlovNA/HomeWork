import pygame
from pygame.draw import *
from random import randint

pygame.init()

FPS = 30
screen = pygame.display.set_mode((1000, 800))

RED = (255, 0, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)
GREEN = (0, 255, 0)
MAGENTA = (255, 0, 255)
CYAN = (0, 255, 255)
BLACK = (0, 0, 0)
COLORS = [RED, BLUE, YELLOW, GREEN, MAGENTA, CYAN]
n = 1
i = 0
ball_number = 5


def new_ball():
    """
    создает новый шарик
    """
    global x, y, r, v_x, v_y, color
    x = randint(100, 900)
    y = randint(100, 700)
    r = randint(10, 100)
    v_x = randint(1, 2)
    v_y = randint(1, 2)
    color = COLORS[randint(0, 5)]
    circle(screen, color, (x, y), r)
    return [x, y, r, color, v_x, v_y]


def ball_move():
    '''
    makes ball to move with its' speed
    :param:j - number of the ball
    0: x
    1: y
    2: r
    3: color
    4: v_x
    5: v_y
    '''
    for j in range(len(ball_parameters)):
        ball_parameters[j][0] += ball_parameters[j][4]
        ball_parameters[j][1] += ball_parameters[j][5]
        circle(screen, ball_parameters[j][3], (ball_parameters[j][0], ball_parameters[j][1]), ball_parameters[j][2])
        if ball_parameters[j][0] - ball_parameters[j][2] < 0:
            ball_parameters[j][4] = -ball_parameters[j][4]
            ball_parameters[j][0] = ball_parameters[j][0] + 1
        elif ball_parameters[j][0] + ball_parameters[j][2] > 1000:
            ball_parameters[j][4] = -ball_parameters[j][4]
            ball_parameters[j][0] = ball_parameters[j][0] - 1
        elif ball_parameters[j][1] - ball_parameters[j][2] < 0:
            ball_parameters[j][5] = -ball_parameters[j][5]
            ball_parameters[j][1] = ball_parameters[j][1] + 1
        elif ball_parameters[j][1] + ball_parameters[j][2] > 800:
            ball_parameters[j][5] = -ball_parameters[j][5]
            ball_parameters[j][1] = ball_parameters[j][1] - 1

def is_inside(mouse_x, mouse_y, x_circle, y_circle, r_circle):
    """
returs True if cursor is inside the ball
    :param mouse_x: cursor x coordinate
    :param mouse_y: cursor y coordinate
    :return:
    """
    return (x_circle - mouse_x) ** 2 + (y_circle - mouse_y) ** 2 < r_circle ** 2


def click(event):
    """
    links checking cursor position with event
    """
    for ball in ball_parameters:
        (mouse_x, mouse_y) = event.pos
        if is_inside(mouse_x, mouse_y, ball[0], ball[1], ball[2]) == True:
            temp = is_inside(mouse_x, mouse_y, ball[0], ball[1], ball[2])
            ball_parameters.remove(ball)
            return temp


ball_parameters = [new_ball() for i in range(ball_number)]


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
                    print('nice click')
                    i += 1
                    print('click size: ', i, 'cm')
    ball_move()


    pygame.display.update()
    screen.fill(BLACK)

pygame.quit()
