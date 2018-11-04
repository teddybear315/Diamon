import __main__
from termcolor import cprint

def changeColor(param):
    __main__.color = param[4:]

def changeBgColor(param):
    __main__.bgcolor = "on_" + param[4:] 

def prnt(param):
    if __main__.color != "." and __main__.bgcolor != ".":
        cprint(param[4:], __main__.color, __main__.bgcolor)
    elif __main__.color != ".":
        cprint(param[4:], __main__.color)
    elif __main__.bgcolor != ".":
        cprint(param[4:], "white", __main__.bgcolor)
    else:
        cprint(param[4:])