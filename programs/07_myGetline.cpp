#include <iostream>
using namespace std;

unsigned min(unsigned a, unsigned b)
{
    if (a < b)
        return a;
    else
        return b;
}

char* resize(const char* str, unsigned size, unsigned new_size)
{
    char* new_mem = new char[new_size];
    for (int i = 0; i < min(size, new_size); i++) {
        new_mem[i] = str[i];
    }
    delete[] str;
    return new_mem;
}

char* getline()
{
    char ch;
    int len = 0, str_size = 128;
    char* str = new char[str_size];
    str[0] = '\0';

    while (cin.get(ch) && ch != '\n') {
        len++;
        if (len <= str_size) {
            str[len - 1] = ch;
        }
        else {
            str = resize(str, str_size, str_size + 128);
            str_size += 128;
            str[len - 1] = ch;
        }
    }

    if (len > 0) {
        len++;
        if (len <= str_size) {
            str[len - 1] = '\0';
        }
        else {
            str = resize(str, str_size, str_size + 1);
            str[len - 1] = '\0';
        }
    }

    return str;
}

int main()
{
    char* str;
    while (1) {
        str = getline();
        if (str != 0) {
            cout << str << endl;
        }
        delete[] str;
    }
}