m=input()
n=len(m)
if n%2==0:
    a=m[n//2-1]
    b=m[n//2]
    c=a+b
    print("中间的两个字符是：%10s"%c)
else:
    a=m[(n+1)//2-1]
    print(a)