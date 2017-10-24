/**
 * Array rotation
 * Using GCD
 */
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void rotate(int arr[], int n, int d)
{
    int g = gcd(d,n);
    int i,j,k,temp;
    for(i=0;i<g;i++)
    {
        temp = arr[i];
        j=i;
        while(1)
        {
            k=j+d;
            if(k>=n)
                k=k-n;
            if(k==i)
                break;
            arr[j] = arr[k];
            j=k;
        }
        arr[j] = temp;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7, k = 2;
    cout<<"Before rotate\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    rotate(arr,n,k);
    cout<<"\nAfter rotate\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
