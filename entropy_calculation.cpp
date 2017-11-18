#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "math.h"
using namespace std;

int HuffmanEncoding(string str)
{
    string substr[1000];
    int count[1000], k=0;


    cout << "The string is : " <<  str << "\n";
    //x = atoi(str.c_str());
    for (int i=0; i< str.length(); i=i+2)
    {
        substr[k] = str.substr(i,2);
        k++;
    }

    int size = k;
    cout << "Total number of symbols is: " << size << "\n";
    for(int i=0; i<size; i++)
    {
        count[i] = 0;
    }


    for (int i=0; i< size; i++)
    {

        for(int j=0; j< size; j++)
        {
            if (substr[i] == substr[j]){
                count[i]++;
            }

        }
        cout << "Count of " << substr[i] << count[i];
    }

    float p[size];
    float entropy=0;
    float sum = 0;
    for(int i=0;i<size; i++)
    {
        sum = sum + count[i];
    }
    cout << "Sum of all frequencies is :" << sum << "\n";

    for(int i=0;i<size; i++)
    {
        p[i] = count[i]/sum;
    }

    float logval;

    for(int i=0;i<size; i++)
    {
        logval = log2(p[i]);
        entropy = entropy - p[i]*logval;

    }

    cout << "Entropy is: " << entropy << "\n";
    cout << "Total number of bits: " << size* entropy ;
    return 0;
}

int main() {

    int x;

    std::ifstream input;
    string str1,str;
    input.open("/Users/dipayandutta/CLionProjects/EPIProblems/input.txt");
    while(!input.eof()) {
        getline(input,str1);
        str.append(str1);
    }

    int output = HuffmanEncoding(str);


    input.close();

    return 0;
}