username = "xuhaocheng25"
sum=0
for i in range(len(username)):
    sum+=ord(username[i])
strsum=str(sum)
print(" ".join(str(ord(c)) for c in strsum))
