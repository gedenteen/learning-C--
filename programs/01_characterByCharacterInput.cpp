#include <iostream>
using namespace std;

int main()
{
    char c = '\0';
    while (cin.get(c)) { //return false if error occurred while reading or the end of the input stream is reached)
        cout << c;
    }
}