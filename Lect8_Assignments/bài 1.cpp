//QuickSort 
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân hoạch (partition) cho thuật toán Quick Sort
// Mục tiêu là đưa pivot (chốt) về đúng vị trí của nó trong mảng đã sắp xếp
int partition(int a[], int low, int high) {
    int pivot = a[high];  // Chọn phần tử cuối cùng làm pivot
    int i = low - 1;       // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;              // Tăng chỉ số i
            swap(a[i], a[j]); // Đưa phần tử nhỏ hơn pivot về phía trái
        }
    }

    // Đưa pivot vào đúng vị trí giữa 2 phần (trái nhỏ hơn, phải lớn hơn)
    swap(a[i + 1], a[high]);
    return i + 1; // Trả về chỉ số mới của pivot
}

// Hàm đệ quy thực hiện thuật toán Quick Sort
void quickSort(int a[], int low, int high) {
    if (low < high) {
        // Phân hoạch mảng và nhận được vị trí của pivot sau khi sắp xếp
        int pi = partition(a, low, high);

        // Gọi đệ quy sắp xếp 2 phần trái và phải của pivot
        quickSort(a, low, pi - 1);  // Sắp xếp phần bên trái
        quickSort(a, pi + 1, high); // Sắp xếp phần bên phải
    }
}

int main() {
    int n;
    cin >> n;
    int a[100]; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Gọi hàm Quick Sort để sắp xếp mảng
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i != n - 1) cout << " "; 
    }
    return 0;
}
