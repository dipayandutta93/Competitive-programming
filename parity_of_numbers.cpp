#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int Parity (int x)
{
    int result = 0;
    while(x)
    {
        result ^= x & 1;
        x = x >> 1;
    }
    return result;
}

int Parity2 (int x)
{
    int result = 0;
    while(x)
    {
        result ^= 1;
        x = (x & (x-1));
    }
    return result;
}

int Parity3 (int x)
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 0x1;
}

int main() {

    int x;

    std::ifstream input;
    input.open("/Users/dipayandutta/CLionProjects/EPIProblems/input.txt");
    while(!input.eof())
    {
        string str;
        getline(input,str);

        x = atoi(str.c_str());
        int output = Parity(x);
        int output2 = Parity2(x);
        int output3 = Parity3(x);

        cout << "parity" << x << ":" << output << "\n";
        cout << "parity" << x << ":" << output2 << "\n";
        cout << "parity" << x << ":" << output3 << "\n";
    }

    input.close();

    return 0;
}

