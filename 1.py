def clean(s):
    ans = ""
    for i in s:
        if i!= '_' and i!=';' and i != '-':
            ans += i
    return ans

a = input()
b = input()
c = input()
a = clean(a)
b = clean(b)
c = clean(c)
a = a.lower()
b = b.lower()
c = c.lower()
one = a + b + c
two = a + c + b
three = c + b + a
four = b + c + a
five = c + a + b
six = b + a + c

n = int(input())
for i in range(0,n):
    s = input()
    s = clean(s).lower()
    if s == one or s == two or s == three or s == four or s == five or s == six:
        print("ACC")
    else:
        print("WA")
