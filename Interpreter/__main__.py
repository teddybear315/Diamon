# This interpreter was built by Logan Houston and Luke Whrit from Dualram

import os
import re#eee
from sys import argv
from functions import prnt

def clear():
    print(os.name)
    if os.name == "nt":
        os.system("cls")
    else:
        os.system("clear")

clear()

ram = []
color = "."
bgcolor = "."

def openFile(filename):
    data = open(os.path.dirname(__file__) + filename, "r").read()
    return data

def lex(data):
    data = list(data)
    string = ""
    token = ""
    expr = ""
    state = 0
    n = 0
    for char in data:
        token += char
        if token == " " and state == 0: # replace all spaces if not in string
            token = ""
        elif token == "\n": # if line ending
            token = ""
        elif token == "prnt": # if print function
            ram.append("PRNT")
            token = ""
        elif token == "clr": # if color function
            ram.append("CLR")
            token = ""
        elif token == "bclr": # if background color function
            ram.append("BCLR")
            token = ""
        elif re.search(r"([0-9]+)", token):
            expr += token
            token = ""
        # elif token == "+":
        # elif token == "-":
        # elif token == "*":
        # elif token == "/":
        elif token == "\"" or token == "\'":
            if state == 0: # if entering string
                state = 1
            elif state == 1: # if exiting string
                ram.append("STR:" + string)
                string = ""
                state = 0
                token = ""
        elif state == 1: # if in string
            string += char
            token = ""
    return ram

def parse(data):
    print("RAM: %s" % data)
    i = 0
    while i < len(data):
        if data[i] == "PRNT":
            prnt.prnt(data[i+1])
        elif data[i] == "CLR":
            prnt.changeColor(data[i+1])
        elif data[i] == "BCLR":
            prnt.changeBgColor(data[i+1])
        i += 1

def run():
    data = openFile(argv[1])
    Ram = lex(data)
    parse(Ram)

run()