#!/usr/bin/env python
# encoding: utf-8
"""
011.py

Created by Kyle Wanamaker on 2011-02-26.
Copyright (c) 2011 K. Lowell Design. All rights reserved.
"""

import sys
import os
import numpy as np
import operator


def main():
    infile = "numbers.txt"
    arr = array2d_from_file(infile)
    
    rowmax = array_row_mult(arr, consec_nums=4, ret_tuple=True, ret_loc=True)
    #note the x and y columns will be out of order here so we will have to swap them back
    colmax = array_row_mult(arr.swapaxes(0,1), consec_nums=4, ret_tuple=True, ret_loc=True)
    cl = colmax['loc']
    colmax['loc'] = tuple(reversed(cl))
    
    print rowmax
    print colmax

def array2d_from_file(source):
    arr = np.loadtxt(source, dtype="int")
    return arr

#returns the max product and the multiplicands as a dict
def array_row_mult(numpy_array, consec_nums=None, ret_tuple=False, ret_loc=False):
    maxprod = {'max':0}
    for y in range(len(numpy_array)):
        row = numpy_array[y,]
        #print row
        for x in range(len(row)):
            slc = row[x:x+consec_nums]
            #print slc,
            product = np.prod(slc)
            if product > maxprod['max']:
                maxprod['max'] = product
                if ret_tuple:
                    maxprod['nums']=slc
                if ret_loc:
                    maxprod['loc']= (x+1,y+1)
            #print product
    return maxprod

#def array_diag_mult(numpy_array, consec_nums=None, ret_tuple=False, ret_loc=False):
    



    if product > maxprod['max']:
        maxprod['max'] = product
        if ret_tuple:
            maxprod['nums']=slc
        if ret_loc:
            maxprod['loc']= (x+1,y+1)
    

if __name__ == '__main__':
	main()
