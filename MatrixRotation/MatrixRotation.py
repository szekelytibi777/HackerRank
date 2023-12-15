#!/bin/python3

import math
import os
import random
import re
import sys
import queue

#
# Complete the 'matrixRotation' function below.
#
# The function accepts following parameters:
#  1. 2D_INTEGER_ARRAY matrix
#  2. INTEGER r
#

def matrixRotation(matrix, r):
    def edges_from_horizontal_matrix(matrix, num_rows, num_columns):
        edges = []
        for j in range(int(num_rows/2)):
            # left top to bottom
            edge = []
            for i in range(j, num_columns-2*j):
                edge.append(matrix[i][0j])
            edges.append(edge) 
            # bottom edge left to right
            edge = []
            for i in range(j, num_columns-2*j):
                edge.append(matrix[j*2][i])
            edges.append(edge) 

            # top edge left to right
            edge = []
            for i in range(j, num_columns-2*j):
                edge.append(matrix[j][i])
            edges.append(edge) 
           
        return edges


    def edges_from_vertical_matrix(matrix, num_rows, num_columns):
        edges = []
        for j in range(num_columns/2):
            # top edge left to right
            edge = []
            for i in range(j, num_rows-2*j):
                edge.append(matrix[j][i])
            edges.append(edge) 
            # right edge top to bottom
            edge = []
            for i in range(j, num_rows-2*j):
                edge.append(matrix[j][i])
            edges.append(edge) 
            # bottom edge right to left
            edge = []
            for i in range(j, num_rows-2*j):
                edge.append(matrix[j][i])
            edges.append(edge) 
            # left edge bottom to top
            edge = []
            for i in range(j, num_rows-2*j):
                edge.append(matrix[j][i])
            edges.append(edge) 
        return edges

    def shift_edges(edges, num):
        for s in range(num):
            for edge in edges:
                print(edge)

    num_rows = len(matrix)
    num_columns = len(matrix[0])
    even_rows = num_rows % 2 == 0
    even_columns = num_columns % 2 == 1 
    if num_rows >= num_columns:
        if even_columns:
            edges_from_vertical_matrix(matrix, num_rows, num_columns)
    else:
        if even_rows:
            edges_from_horizontal_matrix(matrix, num_rows, num_columns)

    for m in range(num_rows):
        for n in range(num_columns):
            print(matrix[m][n], end=' ')
        print()

    print(num_rows,"x",num_columns)
    # Write your code here

if __name__ == '__main__':
    matrix = []
    r = None
    if True:
        with open("input01.txt") as f:
            first_multiple_input = f.readline().rstrip().split()
            m = int(first_multiple_input[0])
            n = int(first_multiple_input[1])
            r = int(first_multiple_input[2])
            for _ in range(m):
                matrix.append(list(map(int, f.readline().rstrip().split())))
    else:
        first_multiple_input = input().rstrip().split()
        m = int(first_multiple_input[0])
        n = int(first_multiple_input[1])
        r = int(first_multiple_input[2])
        for _ in range(m):
            matrix.append(list(map(int, input().rstrip().split())))

    matrixRotation(matrix, r)
