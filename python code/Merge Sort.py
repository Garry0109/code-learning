def merge(L,R):
    i=j=0
    result=[]
    while i<len(L) and j<len(R):
        if L[i]<R[j]:
            result.append(L[i])
            i+=1
        else:
            result.append(R[j])
            j+=1
    result.extend(L[i:])
    result.extend(R[j:])
    return result


def mergesort(a):
    if len(a)>1:
        m=(len(a))//2
        left=a[:m]
        right=a[m:]
        left=mergesort(left)
        right=mergesort(right)
        return merge(left,right)
    else:
        return a
if __name__ == "__main__":
    nums = list(map(int, input("请输入多个整数，用空格分隔: ").split()))
    sorted_nums = mergesort(nums)
    print(sorted_nums)