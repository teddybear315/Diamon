# This interpreter was built by Logan Houston and Luke Whrit from Dualkeys

import os
import re
from sys import argv
from time import sleep
from termcolor import cprint

# Variables

ram = []
numStack = []
symbols = {}
color = "."
bgcolor = "."

# Functions

def clear():
    print(os.name)
    if os.name == "nt":
        os.system("cls")
    else:
        os.system("clear")


def changeColor(param):
    global color
    color = param[4:]


def changeBgColor(param):
    global bgcolor
    bgcolor = "on_" + param[4:]


def prnt(param):
    if type(param) != str:
        param = "TNG:" + str(param)
    if color != "." and bgcolor != ".":
        cprint(param[4:], color, bgcolor)
    elif color != ".":
        cprint(param[4:], color)
    elif bgcolor != ".":
        cprint(param[4:], "white", bgcolor)
    else:
        cprint(param[4:])


def openFile(filename):
    data = open(os.path.dirname(__file__) + filename, "r").read()
    data += "<EOF>"
    return data


def lex(data):
    data = list(data)
    # Strings
    string = ""
    token = ""
    expr = ""
    var = ""
    # Booleans
    varStarted = False
    isexpr = False
    state = False
    for char in data:
        token += char
        if token.startswith(";;"): # comment parsing
            if token.endswith("\n") or token.endswith("<EOF>"):
                token = ""
            pass
        elif token == " " and not state and token != "$var": # if space not in string
            token = ""
        elif token == "\n" or token == "<EOF>": # if line ending or eof
            if expr != "" and isexpr:
                ram.append("EXP:" + expr)
                expr = ""
            elif expr != "" and not isexpr:
                ram.append("NUM:" + expr)
                expr = ""
            token = ""
        elif token == "=" and not state and var != "":
            ram.append("VAR:" + var)
            varStarted = False
            token = ""
            var = ""
        elif token == "prnt": # if print function
            ram.append("PRNT")
            token = ""
        elif token == "$clr": # if color function
            ram.append("$CLR")
            token = ""
        elif token == "bclr": # if background color function
            ram.append("BCLR")
            token = ""
        elif token == "wait": # if wait function
            ram.append("WAIT")
            token = ""
        elif token == "$var" and not state:
            varStarted = True
            var += "$" + token[4:]
            token = ""
        elif varStarted:
            var += token
            token = ""
        elif re.search(r"([0-9]+)", token) and not state: # if number and not in string
            expr += token
            token = ""
        elif re.search(r"([\+\-\*\/\(\)\%]+)", token): # if an expression **
            isexpr = True
            expr += token
            token = ""
        elif token == "\"" or token == "\'":
            if not state: # if entering string
                state = True
            elif state: # if exiting string
                ram.append("STR:" + string)
                string = ""
                state = False
                token = ""
        elif state: # if in string
            string += char
            token = ""
    for item in ram:
        if item.startswith("VAR:"):
            symbols[item[4:]] = ram[ram.index(item)+1][4:]
    print(symbols)
    return ram


def parse(data):
    print("RAM: %s" % data)
    i = 0
    while i < len(data):
        if data[i] == "PRNT":
            if data[i+1][:4] == "EXP:":
                prnt(eval(data[i+1][4:]))
            else:
                prnt(data[i+1])
        elif data[i] == "$CLR":
            changeColor(data[i+1])
        elif data[i] == "BCLR":
            changeBgColor(data[i+1])
        elif data[i] == "WAIT":
            sleep(float(int(data[i+1][4:]) / 1000))
        i += 2


def run():
    data = openFile(argv[1])
    Ram = lex(data)
    parse(Ram)


clear()
run()