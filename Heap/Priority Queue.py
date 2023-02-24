'''
Priority Queue:
Queue: First IN Frist Out
하지만 Priority를 정하면 key값에 따라 달라짐

'''

def max_heapify(arr,i,heap_size):
    largest = i
    left = 2*i+1 #root index가 0이므로 2*i가 아닌 2*i+1이다.
    right = 2*i +2
    if(left<heap_size and arr[left]>arr[largest]):
        largest = left
    if(right<heap_size and arr[right]>arr[largest]):
        largest=right
    if largest!=i:
        arr[i],arr[largest]=arr[largest],arr[i]
        max_heapify(arr,largest,heap_size)
        
def Heap_Maximum(arr):
    return arr[0]

def heap_extract_max(heap):
    if len(heap) < 1:
        raise ValueError("Heap underflow")
    max_val = heap[0]
    heap[0] = heap[-1] #heap[-1]로 마지막 인덱스에 접근가능
    del heap[-1] #del을 통해 리스트 값 삭제
    #heap.pop()리스트 마지막 항목 삭제 함수 이용가능
    max_heapify(heap, 0, len(heap))
    return max_val

def parent_index(i):
    return int((i-1)/2)

def heap_increase_key(arr,i,key):
    if key<arr[i]:
        raise ValueError("new key is smaller than current key")
    arr[i]=key
    
    while i>0 and arr[i]>arr[parent_index(i)]:
        
        arr[i],arr[parent_index(i)]=arr[parent_index(i)],arr[i]
        i=parent_index(i)

def max_heap_insert(arr,key):
    arr.append(float("-inf"))
    heap_increase_key(arr,len(arr)-1,key)


arr= [16,14,10,8,7,9,3,2,4,1]
print(arr)
max_heap_insert(arr,15)
print(arr)


