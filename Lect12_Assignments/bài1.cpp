#include <iostream>
#include<fstream>
using namespace std;

const int MAX_N = 1000;     // Giới hạn số đỉnh tối đa
int adj[MAX_N][MAX_N] = {0};      // Ma trận kề để lưu đồ thị
int queue[MAX_N];           // Hàng đợi thủ công
int front = 0, rear = 0;   // Con trỏ hàng đợi
int n, m;             // Số đỉnh, số cạnh, điểm bắt đầu và kết thúc
int tangbac[MAX_N] = {0};

// Thêm phần tử vào hàng đợi
void enqueue(int x) {
    queue[rear++] = x;
}

// Lấy phần tử ra khỏi hàng đợi
int dequeue() {
    return queue[front++];
}
bool test() {
    return front == rear;
}
int main() {
    ifstream infile("F:\\CODE\\input.txt");
    ofstream outfile("F:\\CODE\\output.txt");
    infile >> n >> m;

    // Nhập các cạnh vào ma trận kề
    for (int i = 0; i < m; ++i) {
        int u, v;
        infile >> u >> v;
        adj[u][v] = 1; // Đồ thị có hướng
        tangbac[v]++;
    }
    for (int i = 1;i <= n;++i) {
        if (tangbac[i] == 0) {
            enqueue(i);
        }
    }
    int kq[MAX_N], id = 0;
    while (!test()) {
        int u = dequeue();
        kq[id++] = u;
        for (int v = 1; v <= n; ++v) {
            if (adj[u][v]) {
                tangbac[v]--;
                if (tangbac[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }
    if (id != n) {
        outfile << "Graph has a cycle, no valid topological order.";
    }
    else {
        // Xuất kết quả sắp xếp topo
        for (int i = 0; i < id; ++i) {
            outfile << kq[i] << " ";
        }
    }
    infile.close();
    outfile.close();
    return 0;
}