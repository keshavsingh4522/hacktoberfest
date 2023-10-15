# -*- coding: utf-8 -*-

"""
A python script that takes in ASCII text and renders it in various ASCII art fonts using the Pyfiglet library.
"""

from pyfiglet import Figlet
# pip install pyfiglet


def figletbasic(txt):
    """ FigletBasic Text """
    f = Figlet(font='basic')
    return f'{f.renderText(txt)}'


def figletslant(txt):
    """ FigletSlant Text """

    f = Figlet(font='slant')
    return f'{f.renderText(txt)}'


def figletbulbhead(txt):
    """ FigletBulbLook Text """

    f = Figlet(font='bulbhead')
    return f'{f.renderText(txt)}'


def figlet3d(txt):
    """ Figlet3D Text """

    f = Figlet(font='larry3d')
    return f'{f.renderText(txt)}'


def figletrectangle(txt):
    """ FigletRegtangular Text """

    f = Figlet(font='rectangles')
    return f'{f.renderText(txt)}'


def figletscript(txt):
    """ FigletNeatWriting Text """

    f = Figlet(font='slscript')
    return f'{f.renderText(txt)}'


def figlet():
    """ Main Figlet Function """
    _input = str(input("Enter some text : "))
    print('\n\n#------------ BASIC ------------#', figletbasic(_input), sep='\n\n')
    print('\n\n#------------ SLANT ------------#', figletslant(_input), sep='\n\n')
    print('\n\n#---------- BUBBLEHEAD ---------#', figletbulbhead(_input), sep='\n\n')
    print('\n\n#-------------- 3D -------------#', figlet3d(_input), sep='\n\n')
    print('\n\n#----------- RECTANGLE ---------#', figletrectangle(_input), sep='\n\n')
    print('\n\n#------------ SCRIPT -----------#', figletscript(_input), sep='\n\n')


if __name__ == '__main__':
    figlet()
