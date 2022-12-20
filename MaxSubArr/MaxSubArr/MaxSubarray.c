#include<stdio.h>

typedef struct
{
	int A[100];
	int low;
	int high;
}arrStartToEnd;

arrStartToEnd FindMaxSubArray(int arr[] ,int start, int end)
{
	arrStartToEnd x;
	int mid;
	
	x.low, x.high = start, end;
	x.A[100] = arr;
	if (start == end)
		return x;
	else
	{
		mid = (start + end) / 2;

	}



		
}
int main(void)
{

}