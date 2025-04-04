#include <iostream>
using namespace std;
const int N = 100;
class MaxHeap {
    int Tree[N];     // Mảng đại diện cho cây heap
    int kichThuoc;     // Số lượng phần tử hiện tại trong heap

    // Hàm dồn xuống để đảm bảo tính chất max-heap
    void donXuong(int i) {
        int root = i;
        int trai = 2 * i + 1;    // Vị trí con trái
        int phai = 2 * i + 2;    // Vị trí con phải

        // So sánh node cha với con trái
        if (trai < kichThuoc && Tree[trai] > Tree[root])
            root = trai;

        // So sánh tiếp với con phải
        if (phai < kichThuoc && Tree[phai] > Tree[root])
            root = phai;

        // Nếu node con lớn hơn node cha thì hoán đổi
        if (root != i) {
            swap(Tree[i], Tree[root]);
            donXuong(root);  // Gọi đệ quy để tiếp tục dồn xuống
        }
    }
    // Hàm dồn lên để chèn giá trị mới
    void donLen(int i) {
        while (i > 0 && Tree[(i - 1) / 2] < Tree[i]) {
            // Nếu node hiện tại lớn hơn node cha thì hoán đổi
            swap(Tree[i], Tree[(i - 1) / 2]);
            i = (i - 1) / 2; // Tiếp tục so sánh với cha mới
        }
    }

public:
    MaxHeap() {
        kichThuoc = 0;  // Khởi tạo heap rỗng
    }
    // Hàm chèn một phần tử vào heap
    void chen(int v) {
        if (kichThuoc >= 100) {
            cout << "error\n";
            return;
        }
        Tree[kichThuoc] = v;   // Đưa phần tử vào cuối mảng
        donLen(kichThuoc);     // Dồn lên để đảm bảo tính chất heap
        kichThuoc++;           // Tăng kích thước heap
    }

    // Hàm xóa một phần tử có giá trị v khỏi heap
    void xoa(int v) {
        int i;
        // Tìm vị trí phần tử có giá trị v
        for (i = 0; i < kichThuoc; i++) {
            if (Tree[i] == v)
                break;
        }
        if (i == kichThuoc) {
            cout << "Không tìm thấy giá trị " << v ;
            return;
        }
        // Thay phần tử đó bằng phần tử cuối và giảm kích thước
        Tree[i] = Tree[kichThuoc - 1];
        kichThuoc--;
        // Dồn lên hoặc dồn xuống tùy vị trí
        if (i > 0 && Tree[i] > Tree[(i - 1) / 2])
            donLen(i);
        else
            donXuong(i);
    }
    // Xây dựng heap từ một mảng đầu vào
    void taoHeap(int mang[], int n) {
        kichThuoc = n;
        for (int i = 0; i < n; i++)
            Tree[i] = mang[i];
        // Từ node cha cuối cùng dồn xuống từng node
        for (int i = kichThuoc / 2 - 1; i >= 0; i--)
            donXuong(i);
    }
    // In heap dạng mảng
    void inHeap() {
        for (int i = 0; i < kichThuoc; i++)
            cout << Tree[i] << " ";
        cout << endl;
    }
};
int main() {
    MaxHeap heap;
    int mang[] = { 2, 1, 10, 6, 3, 8, 7, 13, 20 };
    int n = sizeof(mang) / sizeof(mang[0]);
    // Bước 1: Xây dựng heap ban đầu
    heap.taoHeap(mang, n);
    cout << "Max Heap: ";
    heap.inHeap();
    // Bước 2: Chèn thêm các giá trị
    heap.chen(14);
    heap.chen(0);
    heap.chen(35);
    cout << "\nAfter Insert: ";
    heap.inHeap();   
    // Bước 3: Xóa các phần tử
    heap.xoa(6);
    heap.xoa(13);
    heap.xoa(35);
    cout << "\nAfter Delete: ";
    heap.inHeap();
    return 0;
}
/*
1. Xây dựng heap từ mảng ban đầu:
   - Lưu mảng vào Tree
   - Duyệt từ vị trí n/2 - 1 về 0
     -> Gọi donXuong(i) để đảm bảo tính chất heap
2. Hàm donXuong(i):
   - Xác định node lớn nhất giữa node i và 2 node con (trái, phải)
   - Nếu có node con lớn hơn node i:
     -> Hoán đổi node i với node lớn hơn
     -> Gọi đệ quy donXuong tại vị trí mới
3. Hàm donLen(i):
   - Trong khi node i > node cha
     -> Hoán đổi với node cha
     -> Tiếp tục lên trên
4. Hàm chen(value):
   - Gán value vào vị trí cuối `Tree[size]`
   - Tăng size lên 1
   - Gọi donLen(size - 1)
5. Hàm xoa(value):
   - Tìm vị trí i chứa value
   - Gán phần tử cuối heap vào Tree[i]
   - Giảm size
   - Gọi donXuong(i), nếu cần thì donLen(i)
6. In Heap:
   - In từng phần tử trong Tree theo dạng mảng
  
*/
