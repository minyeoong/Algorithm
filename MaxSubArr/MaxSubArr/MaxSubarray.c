///*
//
//파이썬과 다르게 포인터를 이용해서 *max_left, *max_right를 변수로 설정했다.
//
//*/
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//// Function to find the maximum subarray crossing the middle element
//int findMaxCrossingSubarray(int arr[], int low, int mid, int high, int* max_left, int* max_right)
//{
//    int left_sum = INT_MIN, right_sum = INT_MIN;
//    int sum = 0, i, j;
//
//    // Find maximum sum for the left half of the subarray
//    for (i = mid; i >= low; i--) {
//        sum += arr[i];
//        if (sum > left_sum) {
//            left_sum = sum;
//            *max_left = i;
//        }
//    }
//
//    sum = 0;
//
//    // Find maximum sum for the right half of the subarray
//    for (j = mid + 1; j <= high; j++) {
//        sum += arr[j];
//        if (sum > right_sum) {
//            right_sum = sum;
//            *max_right = j;
//        }
//    }
//
//    return left_sum + right_sum;
//}
//
//// Function to find the maximum subarray in a given array
//int findMaximumSubarray(int arr[], int low, int high, int* left, int* right)
//{
//    if (high == low) {
//        *left = low;
//        *right = high;
//        return arr[low];
//    }
//    else {
//        int mid = (low + high) / 2;
//        int left_low, left_high, left_sum;
//        int right_low, right_high, right_sum;
//        int cross_low, cross_high, cross_sum;
//
//        // Find maximum subarray in the left half of the subarray
//        left_sum = findMaximumSubarray(arr, low, mid, &left_low, &left_high);
//
//        // Find maximum subarray in the right half of the subarray
//        right_sum = findMaximumSubarray(arr, mid + 1, high, &right_low, &right_high);
//
//        // Find maximum subarray crossing the middle element
//        cross_sum = findMaxCrossingSubarray(arr, low, mid, high, &cross_low, &cross_high);
//
//        // Determine which subarray has the maximum sum
//        if (left_sum >= right_sum && left_sum >= cross_sum) {
//            *left = left_low;
//            *right = left_high;
//            return left_sum;
//        }
//        else if (right_sum >= left_sum && right_sum >= cross_sum) {
//            *left = right_low;
//            *right = right_high;
//            return right_sum;
//        }
//        else {
//            *left = cross_low;
//            *right = cross_high;
//            return cross_sum;
//        }
//    }
//}
//
//int main()
//{
//    int n, i, low, high, max_sum;
//    int* arr;
//
//    // Get the size of the array and allocate memory
//    printf("Enter the size of the array: ");
//    scanf_s("%d", &n);
//
//    arr = (int*)malloc(n * sizeof(int));
//
//    // Get the elements of the array
//    printf("Enter the elements of the array:\n");
//    for (i = 0; i < n; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    // Find the maximum subarray
//    max_sum = findMaximumSubarray(arr, 0, n - 1, &low, &high);
//
//    // Output the results
//    printf("Maximum subarray:\n");
//    for (i = low; i <= high; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("max sum: %d\n", max_sum);
//}
//

//다시 작성해보기

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int findMaxCrossSubArray(int arr[], int low, int mid, int high, int* max_left, int* max_right)
{
	int left_sum = INT_MIN;
	int sum = 0,i,j;
	for (i = mid; i >= low; i--)
	{
		sum += arr[i];
		if (sum > left_sum) {
			left_sum = sum;
			* max_left = i;
		}
	}

	int right_sum = INT_MIN;
	sum = 0;
	for (j = mid+1; j <=high; j++)
	{
		sum += arr[j];
		if (sum > right_sum) {
			right_sum = sum;
			*max_right = j;
		}
	}
	return left_sum + right_sum;
}
int findMaxSubArray(int arr[], int low, int high, int* left, int*right)
{
	if (low == high)
	{
		*left = arr[low];
		*right = arr[low];
		return arr[low];
		//left,right의 idx를 return하는 것이 아니라 포인터변수에 대입한다.
	}
	else {
		int mid = (low + high) / 2;
		int left_low, left_high, left_sum;
		int right_low, right_high, right_sum;
		int cross_low, cross_high, cross_sum;
		left_sum = findMaxSubArray(arr, low, mid, &left_low, &left_high);
		right_sum = findMaxSubArray(arr, mid+1, high, &right_low, &right_high);
		cross_sum = findMaxCrossSubArray(arr, low, mid, high, &cross_low, &cross_high);

		if (left_sum >= right_sum && left_sum >= cross_sum) {
			*left = left_low;
			*right = left_high;
			return left_sum;
		}
		else if (right_sum >= left_sum && right_sum >= cross_sum) {
			*left = right_low;
			*right = right_high;
			return right_sum;
		}
		else {
			*left = cross_low;
			*right = cross_high;
			return cross_sum;
		}
	}


}
int main()
{
	int n, i, j,low, high, max_sum;
	printf("Enter the size of array: ");
	scanf_s("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	printf("Enter array number:");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	max_sum = findMaxSubArray(arr, 0, n - 1, &low, &high);
	printf("Print MSA index: ");
	for (j = low; j <= high; j++)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
	printf("Print max sum: %d\n",max_sum);
	


}