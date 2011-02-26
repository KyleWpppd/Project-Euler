#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by Kyle Wanamaker on 2011-02-26.
Copyright (c) 2011 K. Lowell Design. All rights reserved.
"""

import sys
import os
import operator

def main():
    pt = PythagoreanTriple()
    desired_sum = 1000
    
    # use a set because we don't want duplucates
    # but we want it sorted...
    triples = list(set(pt.generate_triples(23)))
    triples.sort()
    matches = pt.triple_sum_tester(triples, desired_sum, first_match_only=False)
    for a,b,c in matches:
        print ("Triple (%i, %i, %i) sums to %i" %(a, b, c, desired_sum))
        prod = reduce(operator.mul, (a,b,c))
    print prod



class PythagoreanTriple(object):
    
    # i need a generator here. This is like the perfect case (afaik--wim).
    def generate_triples(self, ceiling):
        for n in range(1, ceiling):
            for m in range(n+1, ceiling+1):
                triple = (m**2 - n**2, 2*m*n, m**2 + n**2)
                yield triple
    
    def triple_sum_tester(self, iterable_triplets=None, test_sum=None, first_match_only=True):
        matching_triplets = []
        if iterable_triplets is None or test_sum is None:
            raise ValueError, "Please check function arguments, something is missing"
        
        for a, b, c in iterable_triplets:
            if a < c and b < c and (test_sum % (a+b+c) == 0):
                #in a true triplet a < b < c, so swap a and b to make it pretty
                if a > b: 
                    a, b = b, a 
            
                k = test_sum / (a + b + c)
                """
                print ("Triple %i*(%i, %i, %i) is a match (%i, %i, %i)" 
                        %(k, a, b, c, k*a, k*b, k*c)
                        )
                """
                #probably should use map for something like this
                matching_triplets.append( (k*a, k*b, k*c) )
                if first_match_only:
                    break
        return list(set(matching_triplets))



if __name__ == '__main__':
    main()

