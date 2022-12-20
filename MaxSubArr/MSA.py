def FindMaximumSubarray(A, low, high):
    if high == low:
        return low, high, A[low]

    else:
        mid = int(low + high) / 2
        (left_low, left_high, left_sum) = FindMaximumSubarray(A, low, mid)
        (right_low, right_high, right_sum) = FindMaximumSubarray(A, mid + 1, high)
        (cross_low, cross_high, cross_sum) = FindMaxCrossingSubarray(A, low, mid, high)

        if left_sum >= right_sum and left_sum >= cross_sum:
            return left_low, left_high, left_sum
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return right_low, right_high, right_sum
        else:
            return cross_low, cross_high, cross_sum

def FindMaxCrossingSubarray(A, low, mid, high):
    left_sum = float("-inf")
    right_sum = float("-inf")
    sum = 0
    for i in range(mid, low - 1, -1):
        sum = sum + A[i]
        if sum > left_sum:
            left_sum = sum
            max_left = i
    sum = 0
    for j in range(mid + 1, high + 1):
        sum = sum + A[j]
        if sum > right_sum:
            right_sum = sum
            max_right = j

    return max_left, max_right, left_sum + right_sum


A = []
n = int(input())
for i in range(n):
    A.append(int(input()))
    
low_idx,high_idx,sum = FindMaximumSubarray(A, 0, n-1)
print(low_idx)
print(high_idx)
print(sum)
