#include <iostream>
using namespace std;
void ucln(int a, int b) //a<b
{
	if (b % a == 0) { cout<< a;}
	else {
		return ucln(b % a, a);
	}
}
int main() {
	int x, y;
	cin >> x >> y;
	if (x > y) {
		ucln(x, y);
	}
	else { ucln(y, x); }
	return 0;
}