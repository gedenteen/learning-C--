#include <iostream>
using namespace std;

void myStrcat(char* to, const char* from)
{
    int len1 = 0, len2 = 0;
    while (*(to + len1) != '\0') {
        len1++;
    }
    while (*(from + len2) != '\0') {
        len2++;
    }
    for (int i = 0; i < len2; i++) {
        *(to + len1 + i) = *(from + i);
    }
    *(to + len1 + len2) = '\0';
}

int main()
{
    char s1[120] = "Some \0";
    char s2[] = "interesting strings\0";
    myStrcat(s1, s2);
    cout << s1 << "\n";
}