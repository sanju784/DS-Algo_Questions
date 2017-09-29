/**
 * Calculate factorial of very large number
 */
 #include <bits/stdc++.h>
 using namespace std;
 #define MAX 1000

 void print(int arr[], int n)
 {
     for(int i=n-1;i>=0;i--)
     cout<<arr[i]<<" ";
 }

int factorial(int n)
{
    int res[MAX];
    res[0] = 1;
    int res_size = 1;
    for(int i=2;i<=n;i++)
    {
        int j=0;
        int carry = 0;
        while(j < res_size)
        {
            int mul = res[j] * i + carry;
            res[j] = mul % 10;
            carry = mul / 10;
            j++;
        }
        while(carry)
        {
            res[res_size] = carry%10;
            carry = carry/10;
            res_size++;
        }
    }
    print(res, res_size);
}

 int main()
 {
     int n=100;
     factorial(n);
 }
