#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int t = b;
	b = a;
	a = t;
}
int main() {
	int k = 10, m = 20;
	swap(k, m);
	cout << k << " " << m << endl; // 20 10
	return 0;
}