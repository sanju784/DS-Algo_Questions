/*********************************************
*
*  Find element in a rotated array
*
*/////////////////////////////////////////////

#include <stdio.h>

int rotateFind(int a[], int n, int x) {
	int start, end, mid;
	start = 0;
	end = n-1;
	while(start <= end) {
		mid = (start + end)/2;
		if(x == a[mid])
			return mid;
		//checking if second half of array is sorted
		//and then checking that is key present in second half
		if(a[mid] <= a[end]) {
			if(x > a[mid] && x <= a[end])
				start = mid + 1;
			else
				end = mid -1;
		}
		//if second half of array is not sorted then first half will be sorted
		//and then checking that is key present in first half
		else
		{
			if(a[start] <= x && x < a[mid])
				end = mid -1;
			else
				start = mid+1;
		}
	}
	return -1;
}

void main() {
   int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int n = sizeof(arr)/sizeof(arr[0]);
   int key = 3;
   printf("%d is at %d position", key, search(arr, n , key));
}


/**
// In recursive way
int search(int arr[], int start, int end, int k)
{
    if(start <= end)
    {
        int mid = (end+start)/2;
        if(arr[mid] == int k)
            return mid;
        //checking if first half of array is sorted
        if(arr[mid] > arr[start])
        {
            if(k < arr[mid] && k >= arr[start])
                return search(arr, start, mid-1, k);
            else
                return search(arr, mid+1, end, k);
        }
        else
        {
            if(k > arr[mid] && k <= arr[end])
                return search(arr, mid+1, end, k);
            else
                return search(arr, start, mid-1, k);
        }
    }
}

*/
