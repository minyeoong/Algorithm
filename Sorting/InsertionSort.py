def Insertion(list=[]):
    for i in range(1,len(list)):
        key = list[i]
        j = i-1
        while j>-1 and list[j]>key:
            list[j+1]=list[j]
            j = j-1
        list[j+1]=key

# list =[5,2,4,6,1,3]
instance = list(map(int,input().split()))
Insertion(instance)
print(instance)
            
        