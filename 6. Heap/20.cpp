/*********************************************
*
*  Implement queue using heap
*
*/////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

class Queue{

    priority_queue <pair<int, int> > pq;
    int cnt;
  public:
      Queue(){
        cnt = 0;
      }
      void push(int n);
      int pop();
      bool isEmpty();
};

void Queue::push(int n) {
  cnt--;
  pq.push(pi(cnt, n));
}

int Queue::pop() {
    if(pq.empty())
        cout<<"\nQueue is Empty.\n";
    else {
      pi val = pq.top();
      cnt++;
      pq.pop();
      return val.second;
    }
}

bool Queue::isEmpty() {
  return pq.empty();
}

int main(){
    Queue* q = new Queue();
    q->push(1);
    q->push(2);
    q->push(3);
    while(!q->isEmpty())
    {
        cout<<q->pop()<<endl;
    }
    return 0;
}
