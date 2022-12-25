#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
using namespace std;

struct String {
    String(const char* str = "") {
        size = strlen(str);
        this->str = new char[size + 1];
        strncpy(this->str, str, this->size);
        this->str[size] = '\0';
    }

    String(size_t n, char c) {
        this->str = new char[n + 1];
        for (int i = 0; i < n; i++) {
            this->str[i] = c;
        }
        this->str[n] = '\0';
        this->size = n;
    }

    ~String() {
        delete[] str;
    }

    /* Реализуйте этот метод. */
    void append(String& other) {
        this->size += other.size; //new size = this->str.size + other.size;
        char* new_str = new char[this->size + 1]; //create pointer to new string
        strcpy(new_str, this->str); //copy old this->str to new string
        strcat(new_str, other.str); //append other string to new string
        delete[] this->str; //free memory of old this->str
        this->str = new_str; //change pointer of this->str
    }

    size_t size;
    char* str;
};

int main()
{
    cout << "<string_name>: <string_value> <string_size>\n";

    String s1("Hello");
    cout << "s1: " << s1.str << " " << s1.size << "\n";

    String s2(10, 'Q');
    cout << "s2: " << s2.str << " " << s2.size << "\n";

    String s3("");
    cout << "s3: " << s3.str << " " << s3.size << "\n";

    s1.append(s2);
    cout << "s1 + s2: " << s1.str << " " << s1.size << "\n";

}