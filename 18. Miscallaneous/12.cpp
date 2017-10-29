/**
 * Shifting all negative number at begin of array
 *
 * Inserting negative at begin of array
 */
#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

void insertAtBegin(int arr[], int n)
{
    int key, j;
    for(int i=1;i<n;i++)
    {
        key = arr[i];

        //If current element is positive, then continue without doing anything
        if(key > 0)
            continue;

        //if current element is negative,
        //shift positive numbers in arr to one position right
        j = i-1;
        while(j >= 0 && arr[j] > 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        //adding negative number at first position before the positive array
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {12,11,-13,-5,6,-7,5,-3,-6};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertAtBegin(arr, n);
    printArr(arr, n);
}
