/**
 * Maximum length valid parentheses
 */
#include <bits/stdc++.h>
using namespace std;

int getMaxLength(string str)
{
    int n = str.length();
    stack<int> s;
    s.push(-1);

    int result = 0;
    for(int i=0;i<n;i++)
    {
        if(str[i] == '(')
            s.push(i);
        else
        {
            s.pop();

            if(!s.empty())
                result = max(result, i-s.top());
            else
                s.push(i);
        }
    }
    return result;
}

int main()
{
    string str = "((()()";
    cout<<getMaxLength(str)<<endl;
    str = "()(()))))";
    cout<<getMaxLength(str)<<endl;
}
