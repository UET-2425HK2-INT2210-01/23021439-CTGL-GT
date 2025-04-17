#include <iostream>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// Hàm đệ quy sinh hoán vị
void hoanvi(int arr[], int start, int n) {
    if (start == n) {
        for (int i = 0; i < n; ++i)
            cout << arr[i];
        cout << "\n";
        return;
    }

    for (int i = start; i < n; ++i) {
        swap(arr[start], arr[i]); // đổi chỗ phần tử đầu với phần tử thứ i
        hoanvi(arr, start + 1, n); // đệ quy cho phần còn lại
        swap(arr[start], arr[i]); // backtrack
    }
}

int main() {
    int n;
    cin >> n;
    int a[100]; // giả sử n <= 10
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;
    hoanvi(a, 0, n);
    return 0;
}
