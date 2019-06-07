#include <iostream>

using namespace std;

int main()
{
    int sum = 0, i = 50;
    
    while (i <= 100 )
    {
        sum += i;
        i++;
    }

    cout << "The Sum of 50 to 100 inclusive is " << sum << endl;

    return 0;
}