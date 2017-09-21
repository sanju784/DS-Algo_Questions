/**
 * Sort array in absolute difference with a given value
 *
 * Compile by g++ -std=c++11 10.cpp
 */

#include <bits/stdc++.h>
using namespace std;

//using self-balancing-binary-search-tree by multimap
//using multimap so as to allow multiple values for a key
void sortAbs(int arr[], int n, int x)
{
    multimap<int, int> m;

    for(int i=0;i<n;i++)
        m.insert(make_pair(abs(x-arr[i]), arr[i]));

    int i=0;
    for(auto it = m.begin(); it != m.end(); it++)
        arr[i++] = (*it).second;
}

int main()
{
    int arr[] = {2,6,8,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    sortAbs(arr, n, x);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}


/**

In C++, self-balancing-bianry-search-tree is implemented by set, map and multimap.
We canft use set here as we have key value pairs (not only keys).
We also canft directly use map also as a single key can belong to multiple values and map allows a single value
for a key. So we use multimap which stores key value pairs and can have multiple values for a key.

1. Store the values in the multimap with the difference with X as key.
2. In multiimap, the values will be already in sorted order according to key
i.e. difference with X because it implements self-balancing-bianry-search-tree internally.
3. Update all the values of array with the values of map so that array has the required output.

*/
