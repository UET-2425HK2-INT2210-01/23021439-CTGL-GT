#include <iostream>
using namespace std;

const int MAX_N = 100;     
const int MAX_X = 10000;   

int main() {
   
    int n, X;
    cin >> n >> X;           
    int a[MAX_N];            
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // Tạo mảng dp đánh dấu tổng nào có thể tạo được từ các phần tử a[]
    bool dp[MAX_X + 1] = { false }; // Khởi tạo tất cả giá trị là false
    dp[0] = true;             // Tổng 0 luôn có thể tạo từ tập rỗng
    for (int i = 0; i < n; ++i) {
        // Duyệt từ X về a[i] để tránh việc sử dụng lại phần tử a[i] nhiều lần
        for (int j = X; j >= a[i]; --j) {
            // Nếu tổng (j - a[i]) có thể tạo được, thì tổng j cũng có thể
            if (dp[j - a[i]]) {
                dp[j] = true;
            }
        }
    }

    // Sau khi duyệt xong, kiểm tra xem có tổng X không
    if (dp[X]) cout << "YES";   // Nếu có -> in YES
    else cout << "NO";          // Nếu không có tập con nào -> in NO

    return 0;
}
