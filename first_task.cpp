#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int arest_khachatryan()
{
    srand(time(0));
    int arr[100];
    int temp, min, max;
    for(int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 1000;
    };
    min = arr[0];
    max = arr[0];
    for(int i = 0; i < 100; i++)
    {
        if(arr[i] < min)
            min = arr[i];

        if(arr[i] > max)
            max = arr[i];
    };
    cout << "maximum - " << max << "  ";
    if (max % 2 == 0) cout << "max is even " << endl;
    else cout << "max is odd " << endl;
    cout << "minimum - " << min << "  ";
    if (min % 2 == 0) cout << "min is even " << endl;
    else cout << "min is odd " << endl;

}
