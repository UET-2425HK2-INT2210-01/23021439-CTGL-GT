#include <iostream>
using namespace std;

int dem(int n,int x=0) {
	
	if (n>9) {
		return dem(n / 10, x + 1);;
	}
	return x+1;
}
int main() {
	int n;
	cin >>n;
	cout << dem(n);
	return 0;
}
