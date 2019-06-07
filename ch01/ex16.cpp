#include <iostream>

using namespace std;

int main()
{
    int sum = 0, value = 0;
    while (cin >> value)    //read until end-of-file, calculating a running total of all values read
        sum += value;
    
    cout << "The Sum is : " << sum << endl;

    return 0;
}