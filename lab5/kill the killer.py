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
n = 0
i = 0
ball_number = 100
queen_number = 5


def new_ball(x, y, v_x, v_y):
    """
    создает новый шарик
    """
    global r, color
    r = randint(10, 100)
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
    """
    return (x_circle - mouse_x) ** 2 + (y_circle - mouse_y) ** 2 < r_circle ** 2


def click(event):
    """
    links checking cursor position with event
    """
    global ball
    for ball in ball_parameters:
        (mouse_x, mouse_y) = event.pos
        if is_inside(mouse_x, mouse_y, ball[0], ball[1], ball[2]) == True:
            temp = is_inside(mouse_x, mouse_y, ball[0], ball[1], ball[2])
            ball_parameters.remove(ball)
            ball_parameters.append(killer_ball(event))
            return temp


def new_queen():
    '''
    draws killer queen 160*205
    v_x_q, v_y_q - queen's speed
    '''
    global x_queen, y_queen, v_x_q, v_y_q
    x_queen = randint(50, 800)
    y_queen = randint(50, 500)
    v_x_q = randint(1, 2)
    v_y_q = randint(1, 2)
    queen_surf = pygame.image.load('killer_queen.png')
    queen_surf.set_colorkey((255, 255, 255))
    screen.blit(queen_surf, (x_queen, y_queen))
    return [x_queen, y_queen, v_x_q, v_y_q]


def queens_gambit():
    '''
    moves killer queen with his speed
    0: x_queen
    1: y_queen
    2: v_x_q
    3: v_y_q
    '''
    for j in range(len(killer_queen)):
        killer_queen[j][0] += killer_queen[j][2]
        killer_queen[j][1] += killer_queen[j][3]
        queen_surf = pygame.image.load('killer_queen.png')
        queen_surf.set_colorkey((255, 255, 255))
        screen.blit(queen_surf, (killer_queen[j][0], killer_queen[j][1]))
        if killer_queen[j][0] < 0:
            killer_queen[j][2] = -killer_queen[j][2]
            killer_queen[j][0] = killer_queen[j][0] + 1
        elif killer_queen[j][0] + 161 > 1000:
            killer_queen[j][2] = -killer_queen[j][2]
            killer_queen[j][0] = killer_queen[j][0] - 1
        elif killer_queen[j][1] < 0:
            killer_queen[j][3] = -killer_queen[j][3]
            killer_queen[j][1] = killer_queen[j][1] + 1
        elif killer_queen[j][1] + 206 > 800:
            killer_queen[j][3] = -killer_queen[j][3]
            killer_queen[j][1] = killer_queen[j][1] - 1
    for j in range(len(killer_queen)):
        killer_queen[j][2] = killer_queen[j][2] + randint(-2, 2)
        killer_queen[j][3] = killer_queen[j][3] + randint(-2, 2)


def queen_is_inside(mouse_x, mouse_y, x_rect, y_rect):
    """
returs True if cursor is inside the queen
    :param mouse_x: cursor x coordinate
    :param mouse_y: cursor y coordinate
    :return:
    """
    return (mouse_x > x_rect and mouse_x < x_rect + 160 and mouse_y > y_rect and mouse_y < y_rect + 205)


def click_queen(event):
    """
    links checking cursor position with event
    """
    for queen in killer_queen:
        (mouse_x, mouse_y) = event.pos
        if queen_is_inside(mouse_x, mouse_y, queen[0], queen[1]) == True:
            temp = queen_is_inside(mouse_x, mouse_y, queen[0], queen[1])
            killer_queen.remove(queen)
            killer_queen.append(new_queen())
            return temp


def killer_ball(event):
    """
    spawns a ball, aimed into the coursor
    """
    (mouse_x, mouse_y) = event.pos
    for j in range(len(killer_queen)):
        new_ball(killer_queen[j][0] + 80, killer_queen[j][1] + 103,
                 5 * 1 / ((1 + ((mouse_y - killer_queen[j][1]) / (mouse_x - killer_queen[j][0] - 80)) ** 2) ** (1 / 2)),
                 5 * ((mouse_y - killer_queen[j][1]) / (mouse_x - killer_queen[j][0] - 80)) /
                 ((1 + ((mouse_y - killer_queen[j][1]) / (mouse_x - killer_queen[j][0] - 80)) ** 2) ** (1 / 2)))


killer_queen = [new_queen() for i in range(queen_number)]


pygame.display.update()
clock = pygame.time.Clock()
finished = False


ball_parameters = [[0, 0, 0, 0, 0, 0] for i in range(ball_number)]
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
            if click_queen(event) == True:
                    print('daisan no bakudan')
                    i += 3
                    print('click size: ', i, 'cm')
        elif event.type == pygame.MOUSEMOTION:
            if n % 30 == 0:
                killer_ball(event)
    ball_move()
    queens_gambit()
    n+=1

    pygame.display.update()
    screen.fill(BLACK)

pygame.quit()
