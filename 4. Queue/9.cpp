/*********************************************
*
*  Reverse first k element of a Queue
*
*  Input  - 11,12,13,14,15,16,17,18,19,20
*           k = 5
*  Output - 14,13,12,11,15,16,17,18,19,20
*
*/////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <deque>

using namespace std;

deque <int> dq;
queue <int> q;

int main() {
  for(int i = 10;i < 100;i += 10) {
    dq.push_back(i);
  }
  int k = 4;
  for(int i = 0;i < k;i++) {
    q.push(dq.front());
    dq.pop_front();
  }
  while(!q.empty()) {
    dq.push_front(q.front());
    q.pop();
  }
  return 0;
}
