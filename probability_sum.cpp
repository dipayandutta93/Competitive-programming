#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;

int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

double output_sum (int n, int k, float p)
{
    double sum =0;
    double comb =1;
    for(int i=k; i<=n; i++)
    {
        comb = factorial(n)/(factorial(i)*factorial(n-i));

        sum = sum + comb*pow(p,i)*pow((1-p),(n-i));
        //cout << n << "\n" << i << "\n" << comb << "\n" << sum << "\n";
    }

    //cout << sum;

    return sum;
}

double output_sum1 (int n, int k, float p)
{
    double sum =0;
    double comb =1;
    for(int i=0; i<=(n-k); i++)
    {
        comb = factorial(n)/(factorial(i)*factorial(n-i));

        sum = sum + comb*pow(p,i)*pow((1-p),(n-i));
        //cout << n << "\n" << i << "\n" << comb << "\n" << sum << "\n";
    }

    //cout << sum;

    return sum;
}

int main() {

    for(int n=10;n<20;n++)
    {
        double output = output_sum(n,(0.55*n),0.4);
        double output2 = output_sum(n,(0.55*n),0.7);

        cout << "for n:" << n << "output is:" << (output + output2)*0.5 << "\n";
    }



    return 0;
}

