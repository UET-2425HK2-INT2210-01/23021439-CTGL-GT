#include <iostream>
using namespace std;
void count_triplets(int n) {
    int a[10];
    int dem = 0;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }for (int i = 1;i < n;i++) {
        if (a[i - 1] + a[i] + a[i + 1] == 0) {
            dem++;
        }
    }cout << dem;
}
int main()
{
    int n;
    cin >> n;
    count_triplets(n);
    return 0;
}