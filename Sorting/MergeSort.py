def merge(A,left,right,mid):
    a=[0]*(mid-left+1)
    b=[0]*(right-mid)
    for i in range(0,mid-left+1):
        a[i]=A[i+left]
    for i in range(0,right-mid):
        b[i]=A[i+mid+1]
    k=left #본 list의 인덱스
    j=0 #b의 idx이다 
    for i in range(0,len(a)): #우선 왼쪽부터 
        while j < len(b) and a[i] > b[j]: #a가 b보다 더 크다면 b를 먼저 넣는다. b의 인덱스가 끝나면 break
            A[k]=b[j]
            j=j+1
            k=k+1 #b를 넣으면 본 list의 idx를 ++한다.
        A[k]=a[i]
        k=k+1#a를 넣어도 본 list의 idx를 ++한다.
    while j < len(b) :#a가 먼저 끝났을 수 있으니 b를 처리해준다. b가 먼저 끝났다면 해당 라인은 실행되지 않는다.
        A[k]=b[j]
        j=j+1
        k=k+1
#####################################################

def mergesort(a,left,right):
    if left<right:
        mid = (left+right)/2
        mergesort(a,left,mid)
        mergesort(a,mid+1,right)
        merge(a,left,right,mid)