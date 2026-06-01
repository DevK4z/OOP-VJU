p = [True] * 10 ** 6
def sieve(n):
    p[0] = p[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if p[i]:
            for j in range(i * i, n + 1, i):
                p[j] = False
n = int(input())
sieve(n)
print("prime" if p[n] else "not prime")