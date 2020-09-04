import time
import os
from tkinter import Tk, Canvas, PhotoImage, mainloop, Label, StringVar, Entry
import tkinter as tk

from math import sin
import random

g_player = 0
g_enemy = 0
g_pl_1 = ''
g_pl_2 = ''


def get_line():
    s = ''
    s1 = os.read(0, 1).decode()
    while (s1 != '\n'):
        if not s1:
            return False
        s += s1
        s1 = os.read(0, 1).decode()
    return s

def get_map(map):
    counter = 0
    s = get_line()
    s = get_line()
    n = len(s)
    while s and s[:5] != 'Piece'[:5]:
        map.append(s[4:])
        counter += 1
        s = get_line()
    return map, [counter, n]

def put(x, y, symb):
    global g_player, g_enemy
    if symb == 'o':
        canvas.create_rectangle(x, y, x + step, y + step, fill='lightred', outline = 'lightgray')
        g_player += 1
    elif symb == 'x':
        canvas.create_rectangle(x, y, x + step, y + step, fill='lightblue', outline = 'lightgray')
        g_enemy += 1

def draw(map):
    for i in range(len(map)):
        for k in range(len(map[i])):
            if map[i][k] != '.':
                put(i * step, k * step, map[i][k])



step = 0

root = Tk()
root.geometry("1000x900+500+100")
root.configure(background='gray17')

map = []
s = get_line()
while (s):
    s = get_line()
    if s and s[:14] == '$$$ exec p1 : ':
        g_pl_1 = s[14:].split('[')[1].split(']')[0].split('/')[-1]
    elif s and s[:14] == '$$$ exec p2 : ':
        g_pl_2 = s[14:].split('[')[1].split(']')[0].split('/')[-1]
    elif s and s[:7] == 'Plateau'[:7]:
        map, shape = get_map(map)
        break
if map != []:
    # print(map)
    # print(g_pl_1)
    # print(g_pl_2)
    pass

while (shape[0]) * step < 750 and (shape[1] - 4) * step < 750:  # 750
    step += 1






canvas = Canvas(root, width=(shape[0]) * step, height=(shape[1] - 4) * step, bg='lightgray', highlightthickness=1, highlightbackground="black")
canvas.pack()


var = StringVar()
var1 = StringVar()

l_none = Label(root, font=("Helvetica", 24), fg='white', bg='gray17', height=1)
l_none.pack()

l = Label(root, textvariable = var, font=("Helvetica", 24), fg='red', bg='gray17', height=1)
l.pack()

l1 = Label(root, textvariable = var1, font=("Helvetica", 24), fg='lightblue', bg='gray17')
l1.pack(side='top')

var1.set("TEST")





def get_maps():
    global g_enemy, g_player, g_pl_1, g_pl_2
    def put(x, y, symb):
        global g_player, g_enemy
        if symb == 'o':
            canvas.create_rectangle(x, y, x + step, y + step, fill='red')
            g_player += 1
        elif symb == 'x':
            canvas.create_rectangle(x, y, x + step, y + step, fill='lightblue')
            g_enemy += 1
        var.set(f"{g_pl_1} - {g_player}")
        var1.set(f"{g_pl_2} - {g_enemy}")

    def draw(map):
        for i in range(len(map)):
            for k in range(len(map[i])):
                if map[i][k] != '.':
                    put(i * step, k * step, map[i][k])
 
    def get_line():
        s = ''
        s1 = os.read(0, 1).decode()
        while (s1 != '\n'):
            if not s1:
                return False
            s += s1
            s1 = os.read(0, 1).decode()
        return s


    def get_map(map):
        piece = []
        counter = 0
        s = get_line()
        s = get_line()
        while s and s[:5] != 'Piece'[:5]:
            map.append(s[4:])
            counter += 1
            s = get_line()
        #return map
        n = int(s.split()[1])
        for k in range(n):
            piece.append(s)
            s = get_line()
        return map, piece

    map = []
    piece = []
    s = get_line()
    while (s):
        s = get_line()
        if s and s[:2] == '==':
            print(s)
        elif s and s[:7] == 'Plateau'[:7]:
            map = []
            map, piece = get_map(map)
            break
    if map != []:
        # print(map)
        draw(map)
        root.after(10, get_maps)



draw(map)
root.after(10, get_maps)

# Exit
def close(event):
    root.withdraw() # if you want to bring it back
    quit() # if you want to exit the entire thing
root.bind('<Escape>', close)

root.mainloop()




