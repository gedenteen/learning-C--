#include <iostream>
using namespace std;

/* class with private fields - we need to get them */
struct Cls {
    Cls(char _c, double _d, int _i) {
        c = _c;
        d = _d;
        i = _i;
    }
private:
    char c;
    double d;
    int i;
};

/* copy of Cls but with public fields, these classes have equal memory offsets for fields */
struct ClsPubl
{
    ClsPubl(char _c, double _d, int _i) {
        c = _c;
        d = _d;
        i = _i;
    }
public:
    char c;
    double d;
    int i;
};

/* functions for getting private fields of Cls */
char& get_c(Cls& cls) {
    void* voidptr = static_cast<void*>(&cls);
    struct ClsPubl* p = static_cast<ClsPubl*>(voidptr);
    return p->c;
}

double& get_d(Cls& cls) {
    void* voidptr = static_cast<void*>(&cls);
    struct ClsPubl* p = static_cast<ClsPubl*>(voidptr);
    return p->d;
}

int& get_i(Cls& cls) {
    void* voidptr = static_cast<void*>(&cls);
    struct ClsPubl* p = static_cast<ClsPubl*>(voidptr);
    return p->i;
}

int main()
{
    struct Cls clsPrv('q', 3.14, 15);
    cout << "clsPrv.c = " << get_c(clsPrv) << "\n";
    cout << "clsPrv.d = " << get_d(clsPrv) << "\n";
    cout << "clsPrv.i = " << get_i(clsPrv) << "\n";

    return 0;
}