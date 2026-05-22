sum=0
name=input("please input your name:")
for i in range(len(name)):
    if name[i] == " ":
        continue
    sum=sum+ord(name[i])
print("sum={}".format(sum))