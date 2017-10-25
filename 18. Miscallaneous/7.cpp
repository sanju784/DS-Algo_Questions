/**
 * Move all spaces to front of string without modifying string
 */
#include <bits/stdc++.h>
using namespace std;

void moveToBegin(char str[])
{
    int i = strlen(str);
    for(int j=i;j>=0;j--)
    {
        if(str[j] != ' ')
            str[i--] = str[j];
    }
    while(i>=0)
        str[i--] = ' ';
}

int main()
{
    char str[] = "abc def xy z";
    printf("%s\n", str);
    moveToBegin(str);
    printf("%s", str);
}
