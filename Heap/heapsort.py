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
        
def build_max_heap(arr):
    for i in range(len(arr)//2-1,-1,-1):
        max_heapify(arr,i,len(arr))


def heap_sort(arr):
    n =len(arr)
    build_max_heap(arr)
    for i in range(n-1,0,-1):
        arr[0],arr[i]=arr[i],arr[0]
        max_heapify(arr,0,i)
        
arr = [4,1,3,2,16,9,10,14,8,7]
heap_sort(arr)
#파이썬에서 배열을 전달할 때 주소도 전달하는 것이기 때문에 함수 안에서 arr을
#변형해도 함수 밖에서도 동일하게 변형된다.

print(arr) # Output: [1, 2, 3, 4, 7, 8, 9, 10, 14, 16]
