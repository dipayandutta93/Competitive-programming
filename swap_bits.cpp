#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int swapBits(int x, int i, int j)
{
    if((x >> i & 0x1) != (x >> j & 0x1))
    {
        int temp = (1 << i) | (1 << j);
        x = x ^ temp;
    }
    else
    {
        //do nothig
    }
    return x;
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

        getline(input,str);
        int i = atoi(str.c_str());

        getline(input,str);
        int j = atoi(str.c_str());


        int output = swapBits(x, i, j);

        cout << "Output after swapped bits is:" << x << ":" << output << "\n";
    }

    input.close();

    return 0;
}
