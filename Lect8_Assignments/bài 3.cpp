#include <iostream>
using namespace std;

const int MAXN = 100;      // tối đa số lượng đồ vật
const int MAXX = 10000;    // tối đa trọng lượng X

int main() {
    int n, X;
    cin >> n >> X;
    int w[MAXN]; // mảng trọng lượng
    int v[MAXN]; // mảng giá trị
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
    }

    // dp[x] là giá trị lớn nhất đạt được với tổng trọng lượng x
    int dp[MAXX + 1] = { 0 };

    // Duyệt từng món đồ
    for (int i = 0; i < n; ++i) {
        // Duyệt ngược để đảm bảo mỗi đồ chỉ được chọn 1 lần
        for (int x = X; x >= w[i]; --x) {
            dp[x] = max(dp[x], dp[x - w[i]] + v[i]);
        }
    }

    cout << dp[X] << endl; // In giá trị lớn nhất có thể đạt được với trọng lượng tối đa X

    return 0;
}
