/*********************************************
*
*  Reverse a Queue
*
*/////////////////////////////////////////////

#include <iostream>
#include <queue>

using namespace std;

void print(queue<int> q)
{
    while(!q.empty())
    {
        printf("%d ", q.front());
        q.pop();
    }
    cout<<endl;
}

void reverse(queue<int> &q)
{
    if(!q.empty())
    {
        int n = q.front();
        q.pop();
        reverse(q);
        q.push(n);
    }
}

int main()
{
    queue<int> q;
    for(int i=1;i<=5;i++)
        q.push(i);
    print(q);
    reverse(q);
    print(q);
}
