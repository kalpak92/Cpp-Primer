//Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl //syntax error

    char s = "Hello World!"; // char should be std::string
    cout << s << endl;

    int k = 0;
    cout << K << endl; // declaration error

    return 0;
}