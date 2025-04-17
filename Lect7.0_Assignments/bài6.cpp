#include <iostream>
using namespace std;

int tong(int n,int x=0) {
	
	if (n>9) {
		return tong(n / 10, x + n%10);
	}
	return x+n;
}
int main() {
	int n;
	cin >>n;
	cout << tong(n);
	return 0;
}
