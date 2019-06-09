#include <iostream>
#include "SalesItem.h"

using namespace std;

int main()
{
    Sales_item item1, item2;

    cin >> item1 >> item2;

    if (item1.isbn() == item2.isbn()) {
        cout << item1 + item2 << endl;
    }
    else {
        cout << "Different ISBN" << endl;
    }

    return 0;
}