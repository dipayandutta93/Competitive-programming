#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

int two_sum (int arr[], int target, int size)
{
    int count = 0;

    for(int i=0; i< size; i++)
        for(int j= i+1; j< size; j++)
            if(arr[j] == target - arr[i])
                count++;
    return count;
}

int two_sum1 (int arr[], int target, int size)
{
    int count = 0,x;
    map <int, int> hashmap;

    for(int i=0; i< size; i++)
    {
        x = target - arr[i];

        if(hashmap.find(x) != hashmap.end())
        {
            count++;
        }
        hashmap[arr[i]] = i;
    }

    return count;
}

int main() {

    int arr[] = {1, 5, 7, -1, 5} ;
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 6;

    int result = two_sum(arr, target, size);
    cout << "The result is 1: " << result;

    result = two_sum1(arr, target, size);

    cout << "The result is 2: " << result;

    return 0;
}

