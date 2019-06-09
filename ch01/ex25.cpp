#include <iostream>
#include "SalesItem.h"

using namespace std;

int main()
{
    Sales_item total;

    if (cin >> total){
        Sales_item trans; // hold the running sum

        while (cin >> trans)
        {
            if (total.isbn() == trans.isbn())
                total += trans;

            else {
                cout << total << endl;
                total = trans; // total now refers to the next book
            }
        }

        cout << total << endl;        
    }
    else {
        cerr << "No Data ? ! " << endl;
        return -1;
    }

    return 0;
}