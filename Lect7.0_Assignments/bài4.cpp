#include <iostream>
using namespace std;

int luythua(int x,int n) {
	if (n == 0) {
		return 1;
	}return x * luythua(x, n - 1);
}
int main() {
	int x,n;
	cin >> x>>n;
	cout << luythua(x,n);
	return 0;
}
