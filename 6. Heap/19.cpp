/*********************************************
*
*  Implement stack using heap
*
*/////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

class Stack{

//here the data is entered with the counter
// the data is extracted using counter
// the last inserted data counter will be highest so it will be extracted first
priority_queue<pair<int, int> > pq;

int cnt;

public:
    Stack(){
      cnt = 0;
    }
    void push(int n);
    void pop();
    int top();
    bool isEmpty();
};

void Stack::push(int n){
  cnt++;
  pq.push(pi(cnt, n));
}

void Stack::pop(){
  if(pq.empty())
    cout<<"Stack is empty";
  else {
    cnt--;
    pq.pop();
  }
}

int Stack::top(){
  pi val = pq.top();
  return val.second;
}

bool Stack::isEmpty(){
  return pq.empty();
}

int main(){
  Stack *s = new Stack();
  s->push(1);
  s->push(2);
  s->push(3);
  while(!s->isEmpty()) {
    cout<<s->top()<<endl;
    s->pop();
  }
  return 0;
}
