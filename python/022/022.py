#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by Kyle Wanamaker on 2011-02-25.
Copyright (c) 2011 K. Lowell Design. All rights reserved.
"""

import sys
import os
import csv
import string

def main():
    namesfound = sortcsv()
    print ("%d Names found" % namesfound)
    with open("names_sorted.txt") as ns:
        linecount, score = 0, 0
        for line in ns:
            linecount += 1
            score += score_ascii_letter_string(line) * linecount
            if linecount % 10 == 0:
                print score
	    
        print "Final tally: ", score


# the format of the names file is expected to be "NAME1","NAME2","NAME3"..."NAME_N"
# the names will unsorted and all capital letters enclosed by double quotes ("") and comma separated
# there is only one line in names.txt, so doing a readline on the file may have crappy performance
# as it tries to load 5000+ names (approx 30,000+ chars). 
# this could probably be used to export a CSV in json or as a pickled list without much add'l work
def sortcsv(namesfile=None, outfile=None):
    namescount = 0
    
    if namesfile is None:
        namesfile = "names.txt"
    
    if outfile is None:
        outfile = "names_sorted.txt"
    
    with open(namesfile) as n:
        #read the data then close the file
        namesReader = csv.reader(n, delimiter=',', quotechar='"') #delimiter and quotechar can probably be eliminated since they are the defaults
        
        with open(outfile, 'w') as of:
        
            for row in namesReader:
                #row will return a list of strings, and we don't care about them 
                # other than them needing to be sorted. If we have more than one line,
                # we'll have merge the sorted lists (this is a general case, not the case
                # specific to problem 022).
                row.sort()
                namescount += len(row)
                
                for name in row:
                    of.write("%s\n" % name)
    
    return namescount

# because we are working with strings, we need to provide for exceptions
# score_ascii_letter_string("COLIN\n") must be 53
def score_ascii_letter_string(ascii_string=None, case_sensitive=False):
    if not case_sensitive:
        ascii_string = ascii_string.upper()
    
    stringsum = 0
    for char in ascii_string:
        if char in string.ascii_letters:
            charscore = ord(char) - 0x40
            stringsum += charscore
        
        else:
            charscore = 0
    return stringsum    
        
    


if __name__ == '__main__':
    main()
	

