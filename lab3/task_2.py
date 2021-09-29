import pygame.draw
from pygame.draw import *
import numpy as np

pygame.init()

FPS = 30
screen = pygame.display.set_mode((500, 500))


# code
def home(xh, yh, h):  # xh, yh - left right corner coordinates; h - similarity coefficient
    rect(screen, (150, 75, 0), (xh, yh, 150 * h, 100 * h), 0)  # house
    polygon(screen, (255, 0, 0), [(xh + 150 * h / 2, yh - 100 * h / 2), (xh, yh), (xh + 150 * h, yh)], 0)  # roof
    rect(screen, (0, 191, 255), (xh + 50 * h, yh + 30 * h, 50 * h, 30 * h), 0)  # window


def tree(xt, yt, t):
    rect(screen, (150, 75, 0), (xt, yt, 15 * t, 60 * t), 0)  # log
    circle(screen, (1, 50, 32), (xt + 15 * t / 2, yt - 30 * t), 30 * t)  # leaves
    circle(screen, (1, 50, 32), (xt + 15 * t / 2 + 30 * t, yt - 30 * t + 15 * t), 30 * t)
    circle(screen, (1, 50, 32), (xt + 15 * t / 2 - 30 * t, yt - 30 * t + 15 * t), 30 * t)
    circle(screen, (1, 50, 32), (xt + 15 * t / 2 + 30 * t, yt - 30 * t - 20 * t), 30 * t)
    circle(screen, (1, 50, 32), (xt + 15 * t / 2 - 30 * t, yt - 30 * t - 20 * t), 30 * t)
    circle(screen, (1, 50, 32), (xt + 15 * t / 2, yt - 30 * t - 50 * t), 30 * t)


def cloud(xc, yc, c):
    circle(screen, (255, 255, 255), (xc, yc), 30 * c, 0)
    circle(screen, (255, 255, 255), (xc + 30 * c, yc + 30 * c), 30 * c, 0)
    circle(screen, (255, 255, 255), (xc + 30 * c, yc - 30 * c), 30 * c, 0)
    circle(screen, (255, 255, 255), (xc + 60 * c, yc), 30 * c, 0)
    circle(screen, (255, 255, 255), (xc + 90 * c, yc + 30 * c), 30 * c, 0)
    circle(screen, (255, 255, 255), (xc + 90 * c, yc - 30 * c), 30 * c, 0)
    circle(screen, (255, 255, 255), (xc + 120 * c, yc), 30 * c, 0)


def sun(xs, ys, s, n):
    circle(screen, (255, 255, 0), (xs, ys), 30 * s)  # sun body
    for k in range(n + 1):  # sun rays
        polygon(screen, (255, 255, 0),
                [(xs + 45 * s * np.cos(np.pi / n * (k - 1 / 2)), ys - 45 * s * np.sin(np.pi / n * (k - 1 / 2))),
                (xs + 30 * s * np.cos(np.pi * (k - 1) / n), ys - 30 * s * np.sin(np.pi * (k - 1) / n)),
                (xs + 30 * s * np.cos(np.pi * k / n), ys - 30 * s * np.sin(np.pi * k / n))], 0)
    for k in range(n + 1):
        polygon(screen, (255, 255, 0),
                [(xs + 45 * s * np.cos(np.pi / n * (k - 1 / 2)), ys + 45 * s * np.sin(np.pi / n * (k - 1 / 2))),
                (xs + 30 * s * np.cos(np.pi * (k - 1) / n), ys + 30 * s * np.sin(np.pi * (k - 1) / n)),
                (xs + 30 * s * np.cos(np.pi * k / n), ys + 30 * s * np.sin(np.pi * k / n))], 0)


rect(screen, (66, 170, 255), (0, 0, 500, 250), 0)  # sky
rect(screen, (0, 128, 0), (0, 250, 500, 250), 0)  # grass
cloud(250, 70, 1)
tree(320, 220, 1)
home(50, 175, 1)
sun(450, 50, 1, 10)
# code

pygame.display.update()
clock = pygame.time.Clock()
finished = False

while not finished:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True

pygame.quit()
