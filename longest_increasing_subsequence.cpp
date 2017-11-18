#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int lis(int arr[], int size)
{
    int lis_arr[20];

    for(int i=0; i <size; i++)
    {
        lis_arr[i] = 1;
    }

    for(int i=0; i< size; i++)
    {
        for(int j=0; j<i; j++)
        {
            if((arr[j] < arr[i]) && (lis_arr[i] < lis_arr[j]+1))
            {
                lis_arr[i] = lis_arr[j]+1;
            }
        }
    }

    int max =0;
    for(int i=0; i <size; i++)
    {
        if(lis_arr[i]> max){
            max = lis_arr[i];
        }
    }

    return max;
}

int main()
{

    std::ifstream input;
    input.open("/Users/dipayandutta/CLionProjects/EPIProblems/input.txt");
    while(!input.eof())
    {
        string str;
        int arr[10];
        getline(input,str);
        int size = atoi(str.c_str());

        for(int i=0; i< size; i++)
        {
            getline(input,str);
            arr[i] = atoi(str.c_str());
        }

        int out = lis(arr, size);

        cout << " Max increasing subsequence is :"<< out << "\n";
    }

    input.close();

    return 0;
}
