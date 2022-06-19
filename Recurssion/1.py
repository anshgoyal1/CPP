from collections import Counter

def func():
    n = int(input())
    L = [int(i) for i in input().split(' ')]
    # L = sorted(L)
    k = Counter(L)
    ism = False
    for i in k:
        if  k[i] == 1:
            print(L.index(i)+1)
            ism = True
            break
    
    if(ism == False):
        print("-1")
    

t = int(input())
for i in range(t):
    func()