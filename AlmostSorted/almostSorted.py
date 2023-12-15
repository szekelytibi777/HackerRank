#!/bin/python3

import math

#
# Complete the 'almostSorted' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def almostSorted(arr):
    def is_sorted(arr):
        def deltas_in_array(arr):
            prev_value = 0
            prev_sign = 0
            index = 0
            signs = []
            messy_indexes = []
            for value in arr:
                delta = value - prev_value
                sign_of_delta = math.copysign(1, delta)
                signs.append(sign_of_delta)
                if index and prev_sign and prev_sign != sign_of_delta:
                    messy_indexes.append(index-1)
                prev_sign = sign_of_delta
                prev_value = value
                index += 1
            return messy_indexes

        messy_indexes = deltas_in_array(arr)
        num_messy_indexes = len(messy_indexes)
        if num_messy_indexes == 4:
            # Swap -----------------------
            swap_index_0 = messy_indexes[0]
            swap_index_1 = messy_indexes[3]

            return False, "swap", swap_index_0, swap_index_1
        elif num_messy_indexes == 1:
            return False, "swap", 1, 2
        elif num_messy_indexes == 2:
            # Reverse --------------------
            if len(arr) == 3 and arr[messy_indexes[0]] <  messy_indexes[1]:
                return False, "messy", 0, 0
            return False, "reverse", messy_indexes[0], messy_indexes[1]
        elif num_messy_indexes == 0:
            return True, "sorted", 0, 0
        else:
            return False, "messy", 0, 0
    sorted, solution_type, index_0, index_1 = is_sorted(arr)
    sorted = False
    if not sorted:
        if solution_type == "swap":
            # The array is indeed sorted by the operation
            if len(arr) > 2 and True:
                tmp = arr[index_0]
                arr[index_0] = arr[index_1]
                arr[index_1] = tmp
                sorted, solution_type, _, _ = is_sorted(arr)

                if sorted:
                    print("yes")
                    print("swap", index_0+1, index_1+1)
                else:
                    print("no")
            else:
                print("yes")
                print("swap", index_0, index_1)

        elif solution_type == "reverse":
            of_1 = 0
            of_2 = 1
            if len(arr)==3:
                of_1 = 1
                of_2 = 2
            z = list(reversed(arr[index_0+of_1:index_1+of_2]))
            arr[index_0+of_1:index_1+of_2]=z
            sorted, solution_type, _, _ = is_sorted(arr)
            if sorted:
                print("yes")
                if index_1 - index_0 == 1:
                    print("swap", index_0+1, index_1+of_2)
                else:
                    print("reverse", index_0+1, index_1+of_2)
            else:
                print("no")
        else:
            print("no")


if __name__ == '__main__':
    n = 0
    arr = []
    if True:
        with open("input22.txt") as f:
            size_line = f.readline()
            n = int(size_line)
            values_line = f.readline()
            arr = list(map(int, values_line.rstrip().split()))
    else:
        n = int(input().strip())
        arr = list(map(int, input().rstrip().split()))

    # deal with input array size limit
    assert(n >= 2 and n <= 100000)

    almostSorted(arr)
