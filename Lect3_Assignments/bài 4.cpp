
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Queue {
public:
    Node* head = NULL;
    Node* tail = NULL;

    void print() {
        Node* tmp = head;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
        return;
    }

    void enqueue(int x) {
        Node* tmp = tail;
        Node* newNode = new Node(x);
        if (tmp == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tmp->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (head == NULL) {
            return;
        }
        else {
            Node* tmp = head;
            head = tmp->next;
            delete tmp;
        }
    }
};

int main() {
    int n;
    cin >> n;
    string op;
    int x;
    Queue queue;
    for (int i = 1; i <= n; i++) {
        cin >> op;
        if (op == "enqueue") {
            cin >> x;
            queue.enqueue(x);
        }
        if (op == "dequeue") {
            queue.dequeue();
        }
    }
    queue.print();
    return 0;
}

/*
    Mã giả:
        Khai báo Node: data và next;
        Khai báo Queueu: head = tail = NULL;
        Hàm print():
            tmp = head
            Lặp qua danh sách:
                In tmp->data;
                tmp = tmp->next;
        Hàm enqueue(x):
            Tạo newNode mới;
            Nếu danh sách trống: head = tail = newNode;
            Nếu không: tmp = tail, tmp->next = newNode, tail = newNode;
        Hàm dequeu():
            tmp = head, head = tmp->next, xóa tmp;
        Hàm main():
            Đọc các giá trị n, x, op;
            Lặp n lần:
                Nếu op = enqueue, gọi hàm enqueue(x);
                Nếu op= dequeue, gọi hàm dequeue();
            Gọi print()
    Độ phức tạp (chỉ tính hàm enqueue dequeue): O(1);
    Độ phức tạp (toàn chương trình): O(n);
*/
