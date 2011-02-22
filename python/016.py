#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by Kyle Wanamaker on 2011-01-21.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import sys
import os

def sumdigits(num):
    sum = 0
    while(num > 0):
        sum += num % 10
        num /= 10
    return sum


def main():
    s = sumdigits(2**int(sys.argv[1]))
    print s


if __name__ == '__main__':
	main()

