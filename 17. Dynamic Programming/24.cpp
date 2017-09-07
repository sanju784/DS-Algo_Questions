/*********************************************
*
*  Maximum bridges between cities
*
*/////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

typedef struct CityPairs
{
    int north;
    int south;
} city;

bool compare(city a, city b)
{
    if(a.south == b.south)
        return a.north < b.north;
    return a.south < b.south;
}

int maxBridge(city val[], int n)
{
    int lis[n];
    for(int i=0;i<n;i++)
        lis[i]=1;

    sort(val, val+n, compare);
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(val[i].north >= val[j].north && lis[i] < 1 + lis[j])
                lis[i] = 1+lis[j];

    int max = lis[0];
    for(int i=1;i<n;i++)
        if(lis[i] > max)
          max=lis[i];

    return max;
}

int main()
{
    city val[] = {{8,1},{1,2},{4,3},{3,4},{5,5},{2,6},{6,7},{7,8}};
    int n = 8;
    cout<<"Maximum bridges "<<maxBridge(val, n);
}
