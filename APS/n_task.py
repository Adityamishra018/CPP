from math import log

def count_set_bits(x):
    count = 0
    while(x):
        count += x & 1
        x >>= 1
    return count

def set_bit(n,k):
    n = n | 1<<(k-1)
    return n

def unset_bit(n,k):
    n = n ^ 1<<(k-1)
    return n

def check_bit(n,k):
    if(n & 1<<(k-1)):
        return 1
    else:
        return 0

n  = int(input("Enter number of tasks : "))
mat = []
for i in range(n):
    row = [int(i) for i in input("Enter costs row : ").split()]
    mat.append(row)

def optimal_cost(n,mat):
    inf=100000
    dp = [0]
    for i in range((2**n) -1):
        dp.append(inf)
    for i in range(2**n):
        x = count_set_bits(i)
        for j in range(n):
            if (i & 1<<j) == 0:
                dp[i|1<<j] = min(dp[i|1<<j],dp[i] +mat[x][j])
    return dp[(2**n)-1]

print(optimal_cost(n,mat))