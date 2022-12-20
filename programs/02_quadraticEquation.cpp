#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 0) { 
        if (b != 0) {
            // equation b*x + c = 0
            cout << (double)-1 * c / b;
        }
        else {
            if (c == 0) {
                // equation 0 = 0
                cout << "All real numbers\n";
            }
            else {
                // equation c = 0
                cout << "No real roots\n";
            }
        }
        return 0;
    }

    int D = b * b - 4 * a * c;
    if (D < 0) {
        cout << "No real roots\n";
        return 0;
    }

    double x1 = ((double) -1 * b + sqrt(D)) / (2 * a);
    double x2 = ((double) -1 * b - sqrt(D)) / (2 * a);
    cout << x1 << " " << x2 << "\n";
    return 0;
}