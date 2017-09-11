/*********************************************
*
*  Merge k sorted array
*
*/////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define n 4

typedef struct MinHeapNode
{
    int element; //The element to be stored
    int i;       //array from which element is fetched
    int j;       //index of next element to be fetched from array
}node;

node* harr;     //Pointer to array of elements in heap
int heap_size;  //size of min heap, it will be of size k

void swap(node *a, node *b)
{
    node temp = *a;
    *a = *b;
    *b = temp;
}

//to get the minimum value of heap
node getMin()
{
    return harr[0];
}

//recursive function to heapify
void heapify(int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int min = i;
    if(l < heap_size && harr[l].element < harr[i].element)
        min = l;
    if(r < heap_size && harr[r].element < harr[min].element)
        min = r;

    if(min != i)
    {
        swap(&harr[i], &harr[min]);
        heapify(min);
    }
}

//replacing the minimum value of heap an then heapify the heap
void replaceMin(node x)
{
    harr[0] = x;
    heapify(0);
}

//create min heap of size k from the first elements of arrays and heapifyng it
//initializing global variables harr and heap_size
void minHeap(node a[], int size)
{
    heap_size = size;
    harr = a;
    int i = (heap_size - 1)/2;
    while(i >= 0)
    {
        heapify(i);
        i--;
    }
}

/**
 Steps
 1. Creating heap of size k
 2. getting the minimum value from the heap and replacing it with the next element of the array
 */
//merge all array and create a new sorted array
int *mergeKArray(int arr[][n], int k)
{
    int *output = (int*)malloc(sizeof(int)*n*k);

    //creating heap of size k
    //saving first element of k array into heap
    node *harr = (node *)malloc(sizeof(node)*k);
    for(int i=0;i<k;i++)
    {
        harr[i].element = arr[i][0];
        harr[i].i = i;
        harr[i].j = 1;
    }

    //creating heap from all the first elements of the k array
    minHeap(harr, k);

    for(int count=0;count<n*k;count++)
    {
        //getting the minimum element from the heap and saving it the output
        node root = getMin();
        output[count] = root.element;

        //find the next element that will replace the current root of th heap
        //The next element may belong to same array as current root
        //here n is size of each array
        if(root.j < n)
        {
            root.element = arr[root.i][root.j];
            root.j += 1;
            //if root was last element of the array replace it with max
        } else{
            root.element = INT_MAX;
        }

        //replace root with next element of the array
        replaceMin(root);
    }
    return output;
}

int main()
{
    int arr[][n] = {
            {1,3,5,9},
            {0,2,6,7},
            {4,8,10,11},
        };

    int k = sizeof(arr)/sizeof(arr[0]);

    int *output = mergeKArray(arr, k);

    for(int i=0;i<n*k;i++)
        cout<<output[i]<<" ";
}
