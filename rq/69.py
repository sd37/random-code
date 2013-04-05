import math

def compute_euler_toitent(n,all_primes):
    if n in all_primes:
        return n * (1.0 - 1.0/n)
    val = n
    get_primes = set()
    i = 0
    for it in all_primes:
        if val ==  1:
            break
        if it > val:
            break
        while True:
            if val % it == 0:
                if it not in get_primes:
                    get_primes.add(it)
                val = val / it
            else:
                break
            
    ans = n
    for x in get_primes:
        ans = ans * (1.0 - 1.0 / x )
    
    return int(ans)

def compute_primes(n):
    ''' compute all primes less than n'''
    primes = []
    primes.append(0)
    primes.append(0)
    
    for x in range(2,n+1):
        primes.append(1)
            
    i = 2
    
    while i < math.sqrt(n):
        if primes[i]:
            j = i + i
            while j <= n:
                primes[j] = 0
                j = j + i
        i = i + 1
        
    l_primes  = []
    for i in range(len(primes)):
        if primes[i]:
            l_primes.append(i)
    
    
    return l_primes
  
all_primes = compute_primes(1000000)
'''
print compute_euler_toitent(10,all_primes)
'''

l = []
for x in range(2,1000000 + 1):
    y = compute_euler_toitent(x, all_primes)
    l.append(float(x) / y)  
ind = l.index(max(l))
print ind + 2  
    