import sys
M,N = map(int, sys.stdin.readline().split())

def ck_prime(a):
    if a==1:
        return False
    for i in range(2,int(a**0.5)+1):
        if a%i==0:
            return False
    return True

for i in range(M,N+1):
    if ck_prime(i):
        print(i,end=' ')