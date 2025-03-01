#include <iostream>
#include <string>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};
class linkList{
public:
    Node* Head;
    int len = 0;
    linkList() {
        Head = NULL;
    }
    void print() {
        Node* tmp = Head;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (Head == NULL) {
            Head = newNode;
        }
        else {
            Node* temp = Head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        len++;
    }
    void dequeue() {
        if (Head == NULL) {
            return;
        }
        else {
            Node* tmp = Head;
            Head = Head->next;
            delete tmp;
        }
    }
};
int main()
{
    int n;
    cin >> n;
    linkList list;
    for (int i = 0;i < n;i++) {
        string s;
        cin >> s;
        if (s == "enqueue") {
            int x;
            cin >>x;
            list.enqueue(x);
        }
        else if (s == "dequeue") {
         
            list.dequeue();
        }
    }
    list.print();
    return 0;
}


