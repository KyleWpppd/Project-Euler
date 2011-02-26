#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by Kyle Wanamaker on 2011-02-26.
Copyright (c) 2011 K. Lowell Design. All rights reserved.
"""

import sys
import os


def main():
    pt = PythagoreanTriple()
    
    # use a set because we don't want duplucates
    # but we want it sorted...
    triples = list(set(pt.generate_triples(23)))
    triples.sort()
    pt.triple_sum_tester(triples, 1000)
    """
    print triples
    for a,b,c in triples:
        if a < b < c:
            print a, b, c
    """


class PythagoreanTriple(object):
    
    # i need a generator here. This is like the perfect case (afaik--wim).
    def generate_triples(self, ceiling):
        for n in range(1, ceiling):
            for m in range(n+1, ceiling+1):
                triple = (m**2 - n**2, 2*m*n, m**2 + n**2)
                yield triple
    
    def triple_sum_tester(self, iterable_triples, test_sum):
        for a, b, c in iterable_triples:
            if (a < b < c):
                print ("%i\t %i\t %i\t Sum: %i\tDiff: %i " %(a, b, c, a+b+c, a**2 + b**2 - c**2))
                if(test_sum % (a+b+c) == 0):
                    print "Triple (%i, %i, %i) is a match" % a, b, c
        


if __name__ == '__main__':
	main()

