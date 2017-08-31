/*********************************************
*
*  Check who wins election by counting votes
*
*/////////////////////////////////////////////

#include <stdio.h>

void main() {
  int i;
  int candidates[] = {0,1,2};
  int votes[] = {0,2,1,0,0,2,2,2};
  int n = sizeof(votes)/sizeof(votes[0]);
  int c[] = {0,0,0};
  for(i=0;i<n;i++) {
    c[votes[i]]++;
  }
  int win = 0;
  for (i=1;i<3;i++)
    if(c[win] < c[i])
        win = i;
  printf("\nThe winner is %d", win);
}
