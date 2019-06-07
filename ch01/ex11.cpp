#include <iostream>

using namespace std;

int main()
{
    int low = 0, high = 0;
    cout << "Enter two numbers in ascending order : " << endl;
    cin >> low >> high;

    while (low < high)
    {
        cout << low << " ";
        low ++;
    }

    cout << endl;
    return 0;
}