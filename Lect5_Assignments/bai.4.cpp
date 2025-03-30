#include <iostream>
using namespace std;
struct Node {
    int value; // Giá trị của nút
    Node* left; // Con trỏ đến cây con trái
    Node* right; // Con trỏ đến cây con phải

    // Constructor khởi tạo giá trị của nút
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};
class Tree {
    Node* root; // Con trỏ đến gốc của cây nhị phân

public:
    // Constructor khởi tạo cây rỗng
    Tree() : root(nullptr) {}
    // Hàm tìm một nút trong cây
    Node* find(Node* node, int value) {
        if (!node) return nullptr; // Nếu nút không tồn tại, trả về nullptr
        if (node->value == value) return node; // Nếu tìm thấy giá trị trả về node
        Node* leftSearch = find(node->left, value); // Tìm kiếm trong cây con trái
        if (leftSearch) return leftSearch; // Nếu tìm thấy trong cây con trái, trả về kết quả
        return find(node->right, value); // Nếu chưa tìm thấy, tiếp tục tìm trong cây con phải
    }
    // Hàm chèn nút con vào cây
    void them_canh(int parent, int child) {
        Node* parentNode = find(root, parent); // Tìm nút cha trong cây
        if (!parentNode) { // Nếu nút cha chưa tồn tại
            if (!root) { // Nếu cây đang rỗng, tạo nút gốc
                root = new Node(parent);
                root->left = new Node(child);
            }
            return;
        }
        if (!find(root, child)) { // Kiểm tra nếu nút child chưa tồn tại trong cây
            if (!parentNode->left) parentNode->left = new Node(child); // Gán vào con trái nếu trống
            else if (!parentNode->right) parentNode->right = new Node(child); // Gán vào con phải nếu trống
        }
    }
    // Hàm tính chiều cao của cây (tính theo số cạnh)
    int tinh_chieu_cao(Node* node) {
        if (!node) return -1; // Nếu nút không tồn tại, trả về -1 để tính số cạnh
        return 1 + max(tinh_chieu_cao(node->left), tinh_chieu_cao(node->right)); // Tính chiều cao đệ quy
    }

    // Duyệt cây theo thứ tự trước (Preorder): gốc -> trái -> phải
    void preorder(Node* node) {
        if (!node) return;
        cout << node->value << " "; // In giá trị của nút hiện tại
        preorder(node->left); // Duyệt cây con trái
        preorder(node->right); // Duyệt cây con phải
    }

    // Duyệt cây theo thứ tự sau (Postorder): Trái -> phải -> gốc
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left); // Duyệt cây con trái
        postorder(node->right); // Duyệt cây con phải
        cout << node->value << " "; // In giá trị của nút hiện tại
    }

    // Duyệt cây theo thứ tự giữa (Inorder): Trái -> Gốc -> phải
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left); // Duyệt cây con trái
        cout << node->value << " "; // In giá trị của nút hiện tại
        inorder(node->right); // Duyệt cây con phải
    }

    // Kiểm tra xem cây có phải là cây nhị phân tìm kiếm (BST) hay không
    bool is_binary_tree(Node* node) {
        if (!node) return true;
        int count = 0;
        if (node->left) {
            //if (node->left->value >= node->value) return false;
            count++;
        }
        if (node->right) {
            //if (node->right->value <= node->value) return false;
            count++;
        }
        if (count > 2) return false;
        return is_binary_tree(node->left) && is_binary_tree(node->right);
    }

    // In thông tin cây theo yêu cầu
    void print_tree() {
        cout << tinh_chieu_cao(root) << endl; // In chiều cao của cây
        preorder(root); // In thứ tự duyệt trước
        cout << endl;
        postorder(root); // In thứ tự duyệt sau
        cout << endl;

        // Nếu cây là cây nhị phân tìm kiếm, in thứ tự duyệt giữa, ngược lại in "NOT BINARY TREE"
        if (is_binary_tree(root)) {
            inorder(root);
            cout << endl;
        }
        else {
            cout << "NOT BINARY TREE" << endl;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m; // Nhập số lượng nút và số cạnh
    Tree tree;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // Nhập cạnh giữa hai nút
        tree.them_canh(u, v); // Thêm cạnh vào cây
    }

    tree.print_tree(); // In thông tin cây
    return 0;
}
