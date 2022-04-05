from turtle import *


def draw_cross(x, y, width, height):
    # penup()
    # goto(x - width / 2, y)
    # pendown()
    # goto(x + width / 2, y)
    # penup()
    # goto(x, y + height / 2)
    # pendown()
    # goto(x, y - height / 2)
    penup()
    fd(x - width / 2)
    left(90)
    fd(y)
    right(90)
    pendown()
    fd(width)
    penup()
    backward(width / 2)
    left(90)
    fd(height / 2)
    pendown()
    bk(height)
    penup()
    bk(y - height / 2)
    right(90)
    bk(x)


def plot_axes(width, height):
    draw_cross(0, 0, width, height)


def plot_point(x, y):
    print(x, y)
    draw_cross(x, y, 10, 10)


def eval_cubic_eqn(x, c0, c1, c2, c3):
    return c3 * x**3 + c2 * x**2 + c1 * x + c0


def plot_poly(c0, c1=0, c2=0, c3=0, y_scale=False):
    points = []
    for x in range(-250, 251, 50):
        y = eval_cubic_eqn(x, c0, c1, c2, c3)
        points.append([x, y])

    if y_scale:
        y_max = max([p[1] for p in points])

    for p in points:
        x, y = p[0], p[1]
        if y_scale:
            y = y * (250 / y_max)
        plot_point(x, y)

if __name__ == '__main__':
    plot_axes(500, 500)
    plot_poly(-40, -4, 2, y_scale=True)
    # plot_poly(1, 1, 1, 1, True)
