
#include <iostream>
using namespace std;
int main()
{
    int a[5];
    for (int i = 0;i < 5;i++) {
        cin >> a[i];
    }int max = a[0];
    for (int i = 1;i < 5;i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }int min = a[0];
    for (int i = 1;i < 5;i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }cout << max + min;
    return 0;
}
