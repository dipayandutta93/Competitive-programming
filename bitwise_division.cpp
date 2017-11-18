#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int division(int x, int y)
{
    int power = 32;
    int ypower = 1 >> 32;
    int result = 0;

    while(x >= y)
    {
        while(ypower > x)
        {
            --power;
            ypower <<=1;
        }
        result = result + (1 << power);
        x = x - ypower;
    }

    cout << "Remainder is:" << x;
    return result;
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

        int out = division(x, y);

        cout << " Quotient is :"<< out << "\n";
    }

    input.close();

    return 0;
}
