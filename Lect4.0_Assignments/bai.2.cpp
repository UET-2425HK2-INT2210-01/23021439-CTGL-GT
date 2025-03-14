#include <iostream>
using namespace std;

struct Node {
    int data;
    int dut;
    Node* next;
    Node(int x, int p) {
        data = x;
        dut = p;
        next = NULL;
    }
};
class linklist {
public:
    Node* front = NULL;
    linklist() {
    }
    void print() {
        Node* tmp = front;
        while (tmp != NULL) {
            cout << "(" << tmp->data << ", " << tmp->dut << ");";
            if (tmp->next != NULL) { cout << " "; }
            tmp = tmp->next;
        }
        cout << endl;
        return;
    }

    void enqueue(int x, int p) {
        Node* newNode = new Node(x, p);
        if (front == NULL || (front->dut) < p) {
            newNode->next = front;
            front = newNode;
        }
        else {
            Node* temp = front;
            while (temp->next != NULL && temp->next->dut >= p) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void dequeue() {
        if (front == NULL) {
            cout << "Hàng đợi rỗng!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }
};
int main() {
    int n;
    cin >> n;

    linklist list;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "enqueue") {
            int x, p;
            cin >> x >> p;
            list.enqueue(x, p);
        }
        else if (op == "dequeue") {
            list.dequeue();
        }
    }list.print();
    return 0;
}

