#include<iostream>
using namespace std;

double mux(int n) {
    if (n == 0) {
        return 1;
    }
    else if (n > 0) {
        return 2 * mux(n - 1);
    }
    else {
        n = -n;
        return 1 / (2 * mux(n - 1));
    }
}

int main() {
    int n;
    cin >> n;
    cout << mux(n);
    return 0;
}

/*
    Thuật toán 1:
    Mã giả:
        1.Hàm mux(n):
            Nếu n = 0:
                Trả về 1
            Nếu n > 0:
                Trả về 2 * mux(n - 1)
            Nếu n < 0:
                Đặt n = -n
                Trả về 1 / (2 * mux(n - 1))
        2.Hàm main():
            Đọc giá trị n
            Gọi hàm mux(n) và in kết quả
    Độ phức tạp: O(n)
*/

/*
void mux(int n){
    if(n == 0){
        cout << "1";
    }else if(n > 0){
        cout << (1<<n);
    }else{
        n = -n;
        cout << (double)1/(1<<n);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    mux(n);
    return 0;
}
*/

/*
    Thuật toán 2:
    Mã giả:
        1.Hàm mux:
            Nếu n = 0, in ra kết quả là 1
            Nếu n > 0, in ra kết quả của 2^n
            Nếu n < 0, in ra kết quả của 1/(2^n)
        2.Hàm main:
            Đọc giá trị n từ bàn phím
            Gọi hàm mux(n)
    Độ phức tạp: O(1)
*/