n=int(input())
def Fib(n):
    if n<=0:
        return 0
    elif n==1:
        return 1
    else:
        return Fib(n-1)+Fib(n-2)
print(Fib(n))

def fib_loop(n):
    if n<=0:
        return 0
    elif n==1:
        return 1
    a,b=0,1
    for _ in range(2,n+1):
        c=a+b
        a=b
        b=c
    return b
print(fib_loop(n))