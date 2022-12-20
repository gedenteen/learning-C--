#include <iostream>
using namespace std;

#define MAX(x, y, r) { \
    int num1 = (int)(x); \
    int num2 = (int)(y); \
    r = (int)(num1 > num2 ? num1 : num2); \
}

int main()
{
    int a = 10;
    int b = 20;
    int c = 0;
    MAX(a, b, c); // c = 20
    cout << c << endl;
    MAX(a += b, b, c); // a = с = 30
    cout << c << endl;
}