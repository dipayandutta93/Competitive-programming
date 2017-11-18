#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int closestWeight(int x)
{
    for(int i=0; i < sizeof(x)*8; i++)
    {
        if(((x >> i) & 1) != ((x >> (i+1)) & 1))
        {
            int temp = (1 << i) | (1 << (i+1));
            cout << temp;
            x = x ^ temp;
            return x;
        }
    }
    cout << "Closest weight could not be found";
    return 0;
}

int main()
{

    std::ifstream input;
    input.open("/Users/dipayandutta/CLionProjects/EPIProblems/input.txt");
    while(!input.eof())
    {
        string str;
        getline(input,str);
        int x = atoi(str.c_str());

        int output = closestWeight(x);

        cout << "Closest weight is:" << x << ":" << output << "\n";
    }

    input.close();

    return 0;
}

