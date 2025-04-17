#include <iostream>
using namespace std;
void nhiphan(int n, string s = "") {
	if (n==s.size())
	{
		cout << s << endl;
	}
	else {
		nhiphan(n, s + "0");
		nhiphan(n, s + "1");
	}
}
int main() {
	int n;
	cin >> n;
	nhiphan(n);
	return 0;
}