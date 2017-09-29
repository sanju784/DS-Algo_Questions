/**
 * Non-crossing line to connect points of a circle
 */
 #include <bits/stdc++.h>
 using namespace std;

 //here the number of ways to connect n points
 //is same as half of catalan of n
 int countWays(int n)
 {
     int catalan[n+1];
     catalan[0] = catalan[1] = 1;
     for(int i=2;i<=n;i++)
     {
         catalan[i] = 0;
         for(int j=0;j<i;j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
     }
     return catalan[n];
 }

 int main()
 {
     int n=6;
     cout<<countWays(n/2);
 }
