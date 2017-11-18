#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#define MAX_CHAR 256
using namespace std;

bool is_anagram(char* str1, char* str2)
{
    int count1[MAX_CHAR] = {0};
    int count2[MAX_CHAR] = {0};

    if(strlen(str1) != strlen(str2))
    {
        return false;
    }

    for(int i=0; i< strlen(str1); i++)
    {
        count1[str1[i]]++;
        count2[str1[i]]++;
    }

    for(int i=0; i< MAX_CHAR; i++)
    {
        if(count1[i] != count2[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char str1[] = "listen";
    char str2[] = "silentl";
    bool output;

    output = is_anagram(str1, str2);

    cout << " The two strings are anagrams: "<< output << "\n";

    return 0;
}