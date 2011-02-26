#!/usr/bin/env python
# encoding: utf-8
"""
numberlist.py

Created by Kyle Wanamaker on 2011-02-26.
Copyright (c) 2011 K. Lowell Design. All rights reserved.
"""

import sys
import os
import string


def main():
    numbers = []
    with open("numberlist.txt") as nl:
	    for line in nl:
	        numbers.append(int(line))
    total = sum(numbers)
    total_s = str(total)
    print total_s[:10]



if __name__ == '__main__':
	main()

