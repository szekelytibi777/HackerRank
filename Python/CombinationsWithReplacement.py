from itertools import combinations_with_replacement

if __name__ == '__main__':
    n = str(input())
    m = n.split(' ')
    text = sorted(m[0])
    comb = int(m[1])
    
    for v in range(1, comb+1):
        c = combinations_with_replacement(text, v)
        for t in c:
            for q in t:
                print(q, end='')
            print()