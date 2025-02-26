#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[100];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}for (int i = 0;i<n;i++) {
		for (int j = 0;j < n;j++) {
			if (a[i] < a[j]) {
				int c=a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
	}for (int i = 0;i < n;i++) {
		cout << a[i]<<" ";
	}
	return 0;
}

