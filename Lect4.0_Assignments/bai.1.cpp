#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class linklist{
public:
    Node* head = NULL;
    void print() {
        Node* tmp = head;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
        return;
    }

    void append(int x) {
        Node* newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* add = head;
            while (add->next != NULL) {
                add = add->next;
            }
            add->next = newNode;
        }
    }
    void search(int x) {
        Node* se = head;
        int vitri = 0;
        while (se != NULL) {
            if (se->data == x) {
                cout << vitri << endl;
                return;
            }
            se = se->next;
            vitri++;
        }
        cout << "NO" << endl;
    }
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

};

int main() {
    int n;
    cin >> n;
    
    linklist list;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "append") {
            int x;
            cin >> x;
            list.append(x);
        }
        else if (op == "search") {
            int x;
            cin >> x;
            list.search(x);
        }
        else if (op == "reverse") {
            list.reverse();
            list.print();
        }
    }
    return 0;
}

