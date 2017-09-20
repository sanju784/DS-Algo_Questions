/**
 * Reverse an array
 */

#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n)
{
    int l=0, h=n-1;
    while(l < h)
    {
        swap(arr[l], arr[h]);
        l++;
        h--;
    }
}

void revStr(char s[])
{
    int l=0, h=strlen(s)-1;
    while(l < h)
    {
        swap(s[l++], s[h--]);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    char s[] = "sanjeev";
    revStr(s);
    cout<<endl<<s;
}
