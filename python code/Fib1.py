n=int(input())
def fib_loop(n):
    if n<=1:
        return n
    a,b=0,1
    for _ in range(2,n+1):
        c=a+b
        a=b
        b=c
    return b
print(fib_loop(n))
