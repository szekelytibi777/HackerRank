
from itertools import groupby

print " ".join(str((len(list(k)),int(i))) for i,k in groupby(raw_input()))

if __name__ == '__main__':
    n = str(input())
    groups = []
    uniquekeys = []
    for k, g in groupby(n):
        occurence = (len(list(g)), int(k[0]))
        print(occurence, end=' ')
    print()
