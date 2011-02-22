#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by Kyle Wanamaker on 2011-01-20.
Copyright (c) 2010 __MyCompanyName__. All rights reserved.
"""

import sys
import os
import math


def findprimes(ceiling):
    primesDict = {}
    if ceiling >= 2:
        primesDict[2]=0
    for x in range(2, ceiling+1):
        for y in range(2,x+1):
            #print x, y
            if(x % y == 0 and x != y):
                #print 'Reject: ', x, y, x % y
                break
            elif(x == y):
                #print 'Accept: ', x, y, x % y
                primesDict[x]=0
    return primesDict

def lcd(ceiling, primesDict):
    for key in primesDict:
        #print primesDict
        primesDict[key] = int(math.log(ceiling, key))
    sum = 1
    for key, val in primesDict.iteritems():
        sum *= int(key)**val
    print sum
    return sum

def main():
    if len(sys.argv) < 1:
        print 'Calculates the LCD for numbers from 1 to ceiling'
        print 'Usage: 005.py Ceiling'
        return
    else:
        ceiling = int(sys.argv[1])
        if(ceiling > 10000):
            print 'This will take a long time... Control+C to quit...'
        factors = findprimes(ceiling)
        lcd(ceiling, factors)


if __name__ == '__main__':
	main()

