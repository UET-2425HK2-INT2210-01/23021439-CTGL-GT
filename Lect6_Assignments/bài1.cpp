#include <iostream>
using namespace std;

struct Node {
    int data;       // Giá trị của node
    Node* left;     // Con trái
    Node* right;    // Con phải

    // Constructor khởi tạo node mới
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Hàm chèn một phần tử vào BST
Node* insert(Node* root, int value) {
    if (!root) return new Node(value); // Nếu cây rỗng, tạo node mới làm root

    if (value < root->data)
        root->left = insert(root->left, value); // Chèn vào cây con bên trái
    else
        root->right = insert(root->right, value); // Chèn vào cây con bên phải

    return root; // Trả về root của cây sau khi chèn
}

// Hàm tìm node có giá trị nhỏ nhất trong cây con phải
Node* minValueNode(Node* node) {
    while (node && node->left) // Duyệt về node ngoài cùng bên trái
        node = node->left;
    return node;
}

// Hàm xóa một phần tử khỏi BST
Node* deleteNode(Node* root, int key) {
    if (!root) return root; // Nếu cây rỗng, trả về nullptr

    if (key < root->data)
        root->left = deleteNode(root->left, key); // Tìm key ở bên trái
    else if (key > root->data)
        root->right = deleteNode(root->right, key); // Tìm key ở bên phải
    else {
        // Nếu node có một hoặc không có con
        if (!root->left) { // Không có con trái
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) { // Không có con phải
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Nếu node có hai con: tìm node nhỏ nhất ở cây con bên phải
        Node* temp = minValueNode(root->right);
        root->data = temp->data; // Thay thế dữ liệu của root với node nhỏ nhất bên phải
        root->right = deleteNode(root->right, temp->data); // Xóa node nhỏ nhất
    }
    return root;
}

// Hàm duyệt cây theo thứ tự (Inorder)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);  // Duyệt cây con trái
        cout << root->data << " ";  // In ra giá trị của node hiện tại
        inorder(root->right); // Duyệt cây con phải
    }
}
int main() {
    Node* root = nullptr;
    int values[] = { 2, 1, 10, 6, 3, 8, 7, 13, 20 };
    // Chèn các giá trị vào cây
    for (int v : values)
        root = insert(root, v);
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    // Chèn thêm các giá trị mới
    root = insert(root, 14);
    root = insert(root, 0);
    root = insert(root, 35);

    cout << "Sau khi them: ";
    inorder(root);
    cout << endl;

    // Xóa các phần tử 6, 13, 35
    root = deleteNode(root, 6);
    root = deleteNode(root, 13);
    root = deleteNode(root, 35);

    cout << "Sau khi xoa: ";
    inorder(root);
    cout << endl;

    return 0;
}

/*Cấu trúc Node :
data : số nguyên
left : con trỏ đến node bên trái
right : con trỏ đến node bên phải

Hàm tạo Node mới :
Tạo node với giá trị data
Gán left và right là null

Hàm chèn(insert) vào cây BST :
Nếu root là null :
Trả về node mới với giá trị cần chèn
Nếu giá trị nhỏ hơn root->data :
Gọi đệ quy insert vào cây con trái
Ngược lại :
Gọi đệ quy insert vào cây con phải
Trả về root

Hàm tìm node có giá trị nhỏ nhất :
Trong khi node còn node trái :
Di chuyển sang node trái
Trả về node hiện tại(nhỏ nhất)

Hàm xóa(delete) node có giá trị = key :
Nếu root là null :
Trả về null
Nếu key < root->data :
Gọi đệ quy delete bên trái
Nếu key > root.data :
Gọi đệ quy delete bên phải
Nếu key == root->data :
Nếu không có con trái :
Trả về con phải
Nếu không có con phải :
Trả về con trái
Nếu có cả hai con :
Tìm node nhỏ nhất bên phải(minValueNode)
Gán root->data = node nhỏ nhất
Gọi delete đệ quy để xóa node nhỏ nhất
Trả về root

Hàm duyệt (inorder) :
Nếu root không null :
Duyệt bên trái
In ra root->data
Duyệt bên phải
*/
