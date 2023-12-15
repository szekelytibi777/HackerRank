#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'mostBalancedPartition' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY parent
#  2. INTEGER_ARRAY files_size
#

def mostBalancedPartition(parent, files_size):
    number_of_file_sizes = len(parent)
    branches = []
    for j in range(len(parent)):    
    for i in range(number_of_file_sizes):
        parent_index = parent[i]
    # for i in range(number_of_directories):
    print(parent)
    print(files_size)
    # Write your code here
if __name__ == '__main__':
    fptr = open("OUTPUT_PATH", 'w')
    parent_count = None
    parent = []
    files_size_count = None   
    files_size = []
    if True:
        with open("input003.txt") as f:
            parent_count = int(f.readline().strip())
            for _ in range(parent_count):
                parent_item = int(f.readline().strip())
                parent.append(parent_item)
            files_size_count = int(f.readline().strip())

            for _ in range(files_size_count):
                files_size_item = int(f.readline().strip())
                files_size.append(files_size_item)
    else:
        parent_count = int(input().strip())
        for _ in range(parent_count):
            parent_item = int(input().strip())
            parent.append(parent_item)

        files_size_count = int(input().strip())

        for _ in range(files_size_count):
            files_size_item = int(input().strip())
            files_size.append(files_size_item)

    result = mostBalancedPartition(parent, files_size)

    fptr.write(str(result) + '\n')

    fptr.close()