#include<iostream>
#include<string>
using namespace std;
struct Node {
	int data;
	Node* next;
	Node(int d) {
		data = d;
		next = NULL;
	}
};
class linklist {
public:
	Node* Heal;
	int len = 0;
	linklist() {
		Heal = NULL;
	}
	void print() {
		Node* tmp = Heal;
		while (tmp != NULL) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	void insert(int p, int x) {
		if (p < 0 || p > len) {
			cout << " " << endl;
			return;
		}
		Node* newNode = new Node(x);
		if (p == 0) {
			newNode->next = Heal;
			Heal = newNode;
		}
		else {
			Node* temp = Heal;
			for (int i = 0; i < p - 1;i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		len++;
	}
	void remove(int p) {
		if (p < 0 || p >= len || Heal == NULL) {
			cout << " " << endl;
			return;
		}
		Node* temp = Heal;
		if (p == 0) {
			Heal = Heal->next;
			delete temp;
		}
		else {
			Node* prev = NULL;
			for (int i = 0; i < p; i++) {
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			delete temp;
		}
	}
};
int main()
{
	int n;
	cin >> n;
	linklist list;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		if (s == "insert") {
			int p, x;
			cin >> p >> x;
			list.insert(p, x);
		}
		else if (s == "delete") {
			int p;
			cin >> p;
			list.remove(p);
		}
	}
	list.print();
	return 0;
}
