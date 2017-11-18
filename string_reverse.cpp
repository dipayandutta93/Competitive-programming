#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main ()
{
    char str[] ="This a sample string";
    char * pch;
    pch = strtok (str," ");
    string arr[10];
    int i=0;
    string output;

    while (pch != NULL)
    {
        arr[i] = pch;
        reverse(arr[i].begin(),arr[i].end());
        pch = strtok (NULL, " ");
        i++;
    }

    for(int j=0; j< i; j++)
    {
        output.append(arr[j]);
        output.append(" ");
    }

    cout << output;

    return 0;
}