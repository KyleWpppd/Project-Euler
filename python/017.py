#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by Kyle Wanamaker on 2011-01-21.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import sys
import os

numbers = {0: "", 1:"one", 2:"two", 3:"three", 4:"four", 5:"five",
            6:"six", 7:"seven", 8:"eight", 9:"nine", 
            10:"ten", 11:"eleven", 12:"twelve", 13:"thirteen", 14:"fourteen", 15:"fifteen",
        16:"sixteen", 17:"seventeen", 18:"eighteen", 19:"nineteen"}
tenz = {2:"twenty", 3:"thirty", 4:"forty", 5:"fifty", 
        6:"sixty", 7:"seventy", 8:"eighty", 9:"ninety"}
hundred = "hundred"
thousand = "thousand"


def countletters(ceiling):
    letters = 0
    word= '' # yes strings are immutable but this will be a short one...
    for x in range(ceiling+1):
        word = ''
        if x >= 1000:
            letters += len(numbers[x / 1000]+thousand)
            word += numbers[x / 1000]+' '+thousand+' '
            x %= 1000
        if x >= 100:
            letters += len(numbers[x / 100]+hundred)
            word += numbers[x / 100]+' '+hundred+' '
            if (x % 100) != 0:
                letters += len("and")
                word += 'and '
            x %= 100
        if (x % 100) >= 20:
            letters+= len(tenz[x / 10])
            letters+= len(numbers[x % 10])
            word += tenz[x / 10]+' '+numbers[x % 10]
        if(x % 100) < 20:
            letters += len(numbers[x])
            word += numbers[x]
        print letters, word
        



def main():
	countletters(int(sys.argv[1]))
	pass


if __name__ == '__main__':
	main()

