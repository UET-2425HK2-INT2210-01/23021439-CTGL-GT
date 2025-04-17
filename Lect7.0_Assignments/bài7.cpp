#include <iostream>
using namespace std;

void daonguoc(int n) {
	cout << n % 10;
	if (n >= 10) {
		daonguoc(n / 10);
	}
}
int main() {
	int n;
	cin >>n;	
	daonguoc(n);
	return 0;
}
