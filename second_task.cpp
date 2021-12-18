#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int gsfdfgsdfgdfgd()
{
    srand(time(0));
    int arr1[1000];
    int arr2[1000];
    int sum;
    for(int i = 0; i < 1000; i++)
    {
        arr1[i] = rand() % 21 + (-10);
    }
    for(int i = 0; i < 1000; i++)
    {
        arr2[i] = rand() % 21 + (-10);
    }
    for(int i = 0; i < 1000; i++)
    {
        sum += arr1[i] * arr2[i];
    }
    cout << "scalar product:  " << sum;

}

