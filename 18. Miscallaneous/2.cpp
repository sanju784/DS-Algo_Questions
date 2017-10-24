/**
 * Shuffle the deck card
 */

#include <bits/stdc++.h>
using namespace std;

void shuffle(int cards[], int n)
{
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        //getting random of the remaining card
        int r = i + rand() % (n-i);

        swap(cards[i], cards[r]);
    }
}

int main()
{
    int n=52;
    int cards[n];
    for(int i=0;i<n;i++)
        cards[i] = i+1;
    cout<<"Cards before shuffle\n";
    for(int i=0;i<n;i++)
        printf("%d ", cards[i]);

    shuffle(cards, n);

    cout<<"\n\nCards after shuffle \n\n";
    for(int i=0;i<n;i++)
        printf("%d ", cards[i]);
}
