#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int add_two_numbers(int a, int b)
{
    int sum = 0, carryout = 0, carryin = 0,k = 1, ak, bk, tempA = a, tempB = b;
    while(tempA != 0 || tempB != 0)
    {
        ak = a & k;
        bk = b & k;

        carryout = (ak & bk) | (ak & carryin) | (bk & carryin);
        sum = sum | (ak ^ bk ^ carryin);

        carryin = carryout << 1;
        k <<= 1;
        tempA >>= 1;
        tempB >>= 1;
    }
    return sum|carryin;
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
        int y = atoi(str.c_str());

        int sum = 0;
        while(x!=0)
        {
            if (x & 1)
            {
                sum = add_two_numbers(sum,y);
            }
            x >>= 1;
            y <<= 1;

        }

        cout << " Multiplication is :"<< sum << "\n";
    }

    input.close();

    return 0;
}
