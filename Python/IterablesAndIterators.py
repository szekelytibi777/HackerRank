import math

def nCr(n, r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

if __name__ == '__main__':
    N = int(input())
    l = str(input())
    elements = l.split(' ')
    K = int(input())
    N_a = l.count('a')
    if N_a == 0:
        print('0')
    elif N - N_a < K:
        print('1')
    else:
        num = nCr(N - N_a, K)
        denum = nCr(N, K)
        print (round(((denum - num) * 1.0 / denum) ,4))

