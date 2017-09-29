/**
 * LCM of 2 numbers
 */
 #include <bits/stdc++.h>
 using namespace std;

 int gcd(int a, int b)
 {
     if(a%b == 0)
        return b;
    return gcd(b, a%b);
 }

 //using logic that a*b = lcm(a,b)*gcd(a,b)
 int lcm(int a, int b)
 {
     return (a*b)/gcd(a,b);
 }

 int main()
 {
     int a = 9, b = 12;
     cout<<lcm(a,b);
 }
