#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100; // giới hạn kích thước ma trận

int main() {
    int m, n;
    int A[MAX][MAX];     // ma trận A
    int temp[MAX];       // mảng tạm để tính theo từng cặp dòng
    int maxSum = 0;   // tổng lớn nhất tìm được
    int r1, c1, r2, c2;  // tọa độ hình chữ nhật có tổng lớn nhất

    ifstream input("matrix.txt"); //mở file 
    ofstream output("matrix.out"); // đóng file

    if (!input) {
        cerr << "Can't File 'matrix.txt'" << endl; // thông báo khi không tìm thấy file
        return 1;
    }
    input >> m >> n; // đọc vào m hàng và n cột
    // đọc ma trận
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            input >> A[i][j];

    // duyệt tất cả các cặp dòng
    for (int t = 0; t < m; t++) {
        // khởi tạo mảng tạm = 0
        for (int j = 0; j < n; j++)
            temp[j] = 0;

        for (int d = t; d < m; d++) {
            // cộng dồn từng cột từ dòng trên đến dòng dưới
            for (int col = 0; col < n; ++col)
                temp[col] += A[d][col];
            // áp dụng Kadane 1 chiều cho mảng temp
            int currentSum = temp[0];
            int maxCurrent = temp[0];
            int startCol = 0;
            int tempStart = 0;
            int endCol = 0;

            for (int col = 1; col < n; ++col) {
                if (currentSum < 0) {
                    currentSum = temp[col];
                    tempStart = col;
                }
                else {
                    currentSum += temp[col];
                }

                if (currentSum > maxCurrent) {
                    maxCurrent = currentSum;
                    startCol = tempStart;
                    endCol = col;
                }
            }

            // cập nhật kết quả nếu tìm được tổng lớn hơn
            if (maxCurrent > maxSum) {
                maxSum = maxCurrent;
                r1 = t + 1;
                r2 = d + 1;
                c1 = startCol + 1;
                c2 = endCol + 1;
            }
        }
    }
    // ghi kết quả
    output << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum << endl;
    input.close();
    output.close();
    return 0;
}
