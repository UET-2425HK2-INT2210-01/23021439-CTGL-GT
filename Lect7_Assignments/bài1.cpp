#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int MAX = 1000;
    double a[MAX];
    int len = 0;
    ifstream input("numbers.txt ");
    ofstream output("numbers.sorted ");
    if (!input) {
        cerr << "can't open file" << endl;
        return 1;
    }
    // Đọc các số vào mảng
    while (input >> a[len]) {
        len++;      
    }
    input.close();  
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                double temp = a[j];
                a[j] = a[j + 1];
               a[j + 1] = temp;
            }
        }
    }
    // Ghi kết quả ra file
    for (int i = 0; i < len; ++i) {
        output << a[i];
        if (i != len - 1) {
            output << " ";
        }
    }
    output.close();
    return 0;
}
