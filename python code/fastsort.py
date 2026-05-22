d=[8,3,6,7,2,1,4,5]

def main():
    fastsort(d,0,len(d)-1)
    print(d)

def fastsort(A,low,high):
    if low<high:
        p=partition(A,low,high)
        fastsort(A,low,p-1)
        fastsort(A,p+1,high)
    
def partition(A,low,high):
    pivot=A[high]
    i=low
    for j in range(low,high):
        if A[j]<=pivot:
            A[i],A[j]=A[j],A[i]
            i+=1
    A[i],A[high]=A[high],A[i]
    return i

