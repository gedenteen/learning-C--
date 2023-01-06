#include <iostream>
using namespace std;

struct Vector {
public:
    Vector(double x, double y) {
        this->x = x;
        this->y = y;
    }
    Vector() {
        x = y = 0;
    }
    Vector operator +(Vector const& p) const {
        return Vector(x + p.x, y + p.y);
    }
    Vector operator -() const { return Vector(-x, -y); }
    Vector operator -(Vector const& p) const {
        return Vector(x - p.x, y - p.y);
    }
    Vector& operator *=(double d) {
        x *= d;
        y *= d;
        return *this;
    }

    void printCoordinates() {
        cout << "x=" << x << " y=" << y << "\n";
    }

private:
    double x, y;
};

int main()
{
    Vector v1(1.2, 1.2);
    Vector v2(1.0, 2.0);
    v1 = v1 + v2;
    v1.printCoordinates();
    v1 *= 2;
    v1.printCoordinates();
    v1 = v2 - v1;
    v1.printCoordinates();

    return 0;
}