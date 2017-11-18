#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int lis(int arr[], int size)
{
    int lis_arr[20];
    vector<int> L[20];

    for(int i=0; i <size; i++)
    {
        lis_arr[i] = 1;
    }

    for(int i=0; i< size; i++)
    {
        for(int j=0; j<i; j++)
        {
            if((arr[j] < arr[i]) && (L[i].size() < L[j].size()))
            {
                L[i] = L[j];
            }
        }
        L[i].push_back(arr[i]);
    }

    int j =0;
    for(int i=0; i <size; i++)
    {
        if(L[i].size()> L[j].size()){
            j = i;
        }
    }

    for(vector<int>::const_iterator i=L[j].begin(); i != L[j].end(); i++)
    {
        cout << *i << " ";
    }

    return L[j].size();
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
