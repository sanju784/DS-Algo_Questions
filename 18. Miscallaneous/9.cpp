/**
 * Move all spaces to end of string without modifying string
 */
#include <bits/stdc++.h>
using namespace std;

void moveToEnd(char str[])
{
    int i = 0, j;
    for(j=0;j<strlen(str);j++)
    {
        if(str[j] != ' ')
            str[i++] = str[j];
    }
    while(i < j)
        str[i++] = ' ';
}

int main()
{
    char str[] = "abc def xy z";
    printf("%s\n", str);
    int n = strlen(str);
    moveToEnd(str);
    printf("%s", str);
}
