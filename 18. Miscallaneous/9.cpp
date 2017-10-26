/**
 * Move all spaces to end of string without modifying string
 *
 * Reverse the string
 * Move all spaces to begin
 * Reverse again
 */
#include <bits/stdc++.h>
using namespace std;

void reverse(char str[], int start, int end)
{
    while(start < end)
        swap(str[start++], str[end--]);
}

void moveToBegin(char str[])
{
    int i = strlen(str);
    for(int j=i;j>=0;j--)
    {
        if(str[j] != ' ')
            str[i--] = str[j];
    }
    while(i >= 0)
        str[i--] = ' ';
}

int main()
{
    char str[] = "abc def xy z";
    printf("%s\n", str);
    int n = strlen(str);
    reverse(str, 0, n-1);
    moveToBegin(str);
    reverse(str, 0, n-1);
    printf("%s", str);
}
