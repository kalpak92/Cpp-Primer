#include <iostream>
#include "SalesItem.h"

using namespace std;

int main()
{
    Sales_item currItem, valItem;

    if(cin >> currItem)
    {
        int count = 1;

        while (cin >> valItem)
        {
            if (valItem.isbn() == currItem.isbn())
            {
                count++;
            }
            else {
                cout << currItem << " occurs " << count << " times " << endl;
                currItem = valItem;
                count = 1;
            }
        }
        cout << currItem << " occurs " << count << " times " << endl;
    }

    return 0;
}