#!/usr/bin/python

def normalize(str_):
    return str_.capitalize()

def prod(L):
    return reduce(lambda x, y: x* y, L)

if __name__ == "__main__":
    L = [1, 2, 3, 4]
    t = prod(L)
    print t

    L1 = ['adam', 'LISA', 'barT']
    L2 = map(normalize, L1)
    print L2
