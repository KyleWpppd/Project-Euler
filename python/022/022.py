#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by Kyle Wanamaker on 2011-02-25.
Copyright (c) 2011 K. Lowell Design. All rights reserved.
"""

import sys
import os


def main():
	pass

# the format of the names file is expected to be "NAME1","NAME2","NAME3"..."NAME_N"
# the names will unsorted and all capital letters enclosed by double quotes ("")
# there is only one line in names.txt, so doing a readline on the file may have crappy performance
# as it tries to load 5000+ names (approx 30,000+ chars)

# try 1 --  Replace commas with "\n", save to intermediate file,  
#           sort intermediate file to outfile, one name per line and no double quotes

def sortnames(namesfile=None):
    print namesfile
    
    if namesfile is None:
        namesfile = "names.txt"
    
    with open(namesfile) as n:
        #first replace commas with carraige returns
        for line in n:
            l = line.split(',')

    


if __name__ == '__main__':
	main()

