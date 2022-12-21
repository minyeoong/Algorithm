def Merge(list =[],p,q,r):
    n1 = q-p+1
    n2 = r-q
    
    

def MergeSort(list=[],p,r):
    if(p<r):
        q= (p+r)/2
        MergeSort(list=[],p,q)
        MergeSort(list=[],q+1,r)
        Merge(list=[],p,q,r)
        