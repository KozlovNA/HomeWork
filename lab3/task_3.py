import pygame.draw
from pygame.draw import *
import numpy as np

pygame.init()

FPS = 30
screen = pygame.display.set_mode((500, 500))


# code
def home(xh, yh, h):
    """
    The function draws a house.
    :param xh: x-coordinate of the upper left corner of the house
    :param yh: y-coordinate of the upper left corner of the house
    :param h: similarity coefficient
    """
    rect(screen, (150, 75, 0), (xh, yh, 150 * h, 100 * h), 0)  # house
    polygon(screen, (255, 0, 0), [(xh + 150 * h / 2, yh - 100 * h / 2), (xh, yh), (xh + 150 * h, yh)], 0)  # roof
    rect(screen, (0, 191, 255), (xh + 50 * h, yh + 30 * h, 50 * h, 30 * h), 0)  # window


def tree(xt, yt, t):
    """
    The function draws a tree by forming its trunk as a rectangle and all its leaves as six circles.
    :param xt: x-coordinate of the upper left corner of the tree's trunk
    :param yt: y-coordinate of the upper left corner of the tree's trunk
    :param t: similarity coefficient
    """
    green = (1, 50, 32)  # leaf color

    rect(screen, (150, 75, 0), (xt, yt, 15 * t, 60 * t), 0)  # tree's trunk
    circle(screen, green, (xt + 15 * t / 2, yt - 30 * t), 30 * t)  # leaves
    circle(screen, green, (xt + 15 * t / 2 + 30 * t, yt - 30 * t + 15 * t), 30 * t)  # leaves
    circle(screen, green, (xt + 15 * t / 2 - 30 * t, yt - 30 * t + 15 * t), 30 * t)  # leaves
    circle(screen, green, (xt + 15 * t / 2 + 30 * t, yt - 30 * t - 20 * t), 30 * t)  # leaves
    circle(screen, green, (xt + 15 * t / 2 - 30 * t, yt - 30 * t - 20 * t), 30 * t)  # leaves
    circle(screen, green, (xt + 15 * t / 2, yt - 30 * t - 50 * t), 30 * t)  # leaves


def cloud(xc, yc, c):
    """
    The function draws a cloud by forming it from seven white circles.
    :param xc: x-coordinate of the leftmost circle's center in the cloud
    :param yc: y-coordinate of the leftmost circle's center in the cloud
    :param c: similarity coefficient
    """
    white = (255, 255, 255)  # cloud's color

    circle(screen, white, (xc, yc), 30 * c)  # white circle that comprises part of the cloud
    circle(screen, white, (xc + 30 * c, yc + 30 * c), 30 * c)  # white circle that comprises part of the cloud
    circle(screen, white, (xc + 30 * c, yc - 30 * c), 30 * c)  # white circle that comprises part of the cloud
    circle(screen, white, (xc + 60 * c, yc), 30 * c)  # white circle that comprises part of the cloud
    circle(screen, white, (xc + 90 * c, yc + 30 * c), 30 * c)  # white circle that comprises part of the cloud
    circle(screen, white, (xc + 90 * c, yc - 30 * c), 30 * c)  # white circle that comprises part of the cloud
    circle(screen, white, (xc + 120 * c, yc), 30 * c)  # white circle that comprises part of the cloud


def sun(xs, ys, s, n):
    """
    The function draws a sun using a circle and triangles to imitate its rays.
    :param xs: x-coordinate of the sun's center
    :param ys: y-coordinate of the sun's center
    :param s: similarity coefficient
    :param n: half of the number of sun rays
    """
    yellow = (255, 255, 0)  # sun color

    circle(screen, yellow, (xs, ys), 30 * s)  # sun body
    for k in range(n + 1):  # sun rays on the upper side of the sun
        polygon(screen, yellow,
                [(xs + 45 * s * np.cos(np.pi / n * (k - 1 / 2)), ys - 45 * s * np.sin(np.pi / n * (k - 1 / 2))),
                 (xs + 30 * s * np.cos(np.pi * (k - 1) / n), ys - 30 * s * np.sin(np.pi * (k - 1) / n)),
                 (xs + 30 * s * np.cos(np.pi * k / n), ys - 30 * s * np.sin(np.pi * k / n))], 0)
    for k in range(n + 1):  # sun rays on the lower side of the sun
        polygon(screen, yellow,
                [(xs + 45 * s * np.cos(np.pi / n * (k - 1 / 2)), ys + 45 * s * np.sin(np.pi / n * (k - 1 / 2))),
                 (xs + 30 * s * np.cos(np.pi * (k - 1) / n), ys + 30 * s * np.sin(np.pi * (k - 1) / n)),
                 (xs + 30 * s * np.cos(np.pi * k / n), ys + 30 * s * np.sin(np.pi * k / n))], 0)


# drawing the background:
rect(screen, (66, 170, 255), (0, 0, 500, 250), 0)  # sky
rect(screen, (0, 128, 0), (0, 250, 500, 250), 0)  # grass

# drawing the houses, trees, clouds, and the sun:
home(50, 270, 1.25)
home(300, 200, 0.75)
tree(300, 350, 1)
tree(450, 230, 0.75)
cloud(50, 50, 1)
cloud(230, 80, 0.5)
sun(450, 50, 1, 10)
cloud(400, 80, 0.5)


# initialising the code:

pygame.display.update()
clock = pygame.time.Clock()
finished = False

while not finished:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True

pygame.quit()
