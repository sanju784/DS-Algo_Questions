/**
 * Multiply Large Numbers represented as Strings
 *
 * run by g++ -std=c++11 4.cpp
 */
 #include <bits/stdc++.h>
 using namespace std;

string multiply(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();

    if(n1 == 0 || n2 == 0)
        return "0";

    vector<int> result(n1+n2, 0);

    int i_n1=0;
    int i_n2=0;

    for(int i=n1-1;i>=0;i--)
    {
        int carry = 0;
        int nu1 = num1[i] - '0';

        i_n2 = 0;
        for(int j=n2-1;j>=0;j--)
        {
            int nu2 = num2[j] - '0';

            int sum = nu1*nu2 + result[i_n1 + i_n2] + carry;

            carry = sum/10;

            result[i_n1+i_n2] = sum%10;
            i_n2++;
        }

        if(carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }

    int i = result.size() - 1;
    while(i >= 0 && result[i]==0)
        i--;

    if(i==-1)
        return "0";

    string s = "";
    while(i>=0)
        s += std::to_string(result[i--]);

    return s;
}

 int main()
 {
    string str1 = "1235421415454545454545454544";
    string str2 = "1714546546546545454544548544544545";
    cout << multiply(str1, str2);
 }
