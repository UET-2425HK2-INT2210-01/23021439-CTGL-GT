#include<iostream>
using namespace std;

const int MAX = 1000;
int n = 0, a[MAX];

void print() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return;
}

void push(int x) {
    if (n == MAX) { return; }
    a[n] = x;
    n++;
}
void pop() {
    if (n == 0) { return; }
    n--;
}

int main() {
    int n;
    cin >> n;
    int x;
    string op;
    for (int i = 1; i <= n; i++) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            push(x);
        }
        else if(op == "pop") {
            pop();
        }
    }
    print();
    return 0;
}

/*
    Mã giả:
        Khởi tạo MAX = 1000, n = 0, mảng a[MAX];
    Hàm print():
        In ra các phần tử của mảng a;
    Hàm push(x):
        Nếu n = MAX thì return;
        Nếu n < MAX, gán push[n] = x, rồi tăng n thêm 1;
    Hàm pop():
        Nếu n == 0 thì return;
        Nếu n > 0 thì giảm n đi 1;
    Hàm main():
        Đọc các giá trị n, x, op;
        Lặp n lần:
            Nếu op = push, gọi hàm push(x);
            Nếu op = pop, gọi hàm pop();
        In ra giá trị của mảng;

    Độ phức tạp (chỉ tính hàm push và pop): O(1);
*/