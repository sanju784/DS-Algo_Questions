/**
 * Next Greater Element in array
 */
#include <bits/stdc++.h>
using namespace std;

void printNGE(int arr[], int n)
{
    int element, next;
    stack<int> s;
    s.push(arr[0]);
    for(int i=1;i<n;i++)
    {
        next = arr[i];
        if(!s.empty())
        {
            element = s.top();
            s.pop();
            while(element < next)
            {
                cout<<element<<" "<<next<<endl;
                if(s.empty())
                    break;
                element = s.top();
                s.pop();
            }
            if(element > next)
                s.push(element);
        }
        s.push(next);
    }
    while(!s.empty())
    {
        element = s.top();
        s.pop();
        cout<<element<<" "<<-1<<endl;
    }
}

int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
}
