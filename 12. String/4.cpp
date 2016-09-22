/*********************************************
*
*  check if input string can be broken and found in dictionary
*
*/////////////////////////////////////////////

//substr(pos,len) - return a sub string of length len starting from position pos

#include <bits/stdc++.h>

using namespace std;

bool dictonaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);

    for(int i=0;i<n;i++)
        if(dictionary[i].compare(word) == 0)
            return true;
    return false;
}

bool wordBreak(string str)
{
    int size = str.size();
    if(size==0)
        return true;

    //wb[i] is true if str[0..i-1] is present in dictionary word otherwise false
    bool wb[size+1];
    memset(wb, 0, sizeof(wb)); // initialize all value as false

    for(int i=1; i<=size;i++)
    {
        //if wb[i] is false, then check if current string is in dictionary
        if(wb[i] == false && dictonaryContains(str.substr(0,i)))
            wb[i] = true;

        //if wb[i] is true then we start search from the next character
        if(wb[i] == true)
        {
            if(i==size)
                return true;

            for(int j=i+1; j<=size;j++)
            {
                if(wb[j] == false && dictonaryContains(str.substr(i,j-i)));
                  wb[j] = true;

                if(j==size && wb[j] == true)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    return 0;
}
