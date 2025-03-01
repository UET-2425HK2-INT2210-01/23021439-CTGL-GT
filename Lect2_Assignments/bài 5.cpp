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
	void push(int x) {
		Node* newNode = new Node(x);
		if (Heal == NULL) {
			Heal = newNode;
		}
		else {
			Node* tmp = Heal;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = newNode;
			newNode->next = NULL;
		}
		len++;
	}
	void pop()
	{
		if (len != 0)
		{
			Node* loop = Heal;
			while (loop->next->next != NULL) loop = loop->next;

			Node* trash = loop->next;
			delete trash;
			loop->next = NULL;
			len;
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
		if (s == "push") {
			int  x;
			cin >> x;
			list.push(x);
		}
		else if (s == "pop") {
			list.pop();
		}
	}
	list.print();
	return 0;
}