//링크드 리스트를 이용해 구현 

#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int e) {
		this->data = e;
		this->next = NULL;
	}
};
class linkedStack {
public:
	Node* head;
	Node* tail;
	int n;
	linkedStack() {
		this->head = NULL;
		this->tail = NULL;
		this->n = 0;
	}
	int size() {
		return n;
	}
	bool empty() {
		return n == 0;
	}
	int top() {
		if (empty())return -1;
		else return head->data;
	}
	void push(int e) {
		Node* newNode = new Node(e);
		if (empty()) {
			head = tail = newNode;
			n++;
		}
		else {
			newNode->next = head;
			head = newNode;
			n++;
		}
	}
	int pop() {
		if (empty()) return -1;
		else {
			Node* temp = head;
			head = head->next;
			n--;
			return temp->data;
		}
	}
};
int main() {
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int size = s.size();
		linkedStack aS;
		for (int i = 0; i < size; i++) {
			char si = s.at(i);
			if (si == '*')
			{
				int a = aS.pop();
				int b = aS.pop();
				int x = b * a;
				aS.push(x);
			}
			else if (si == '+')
			{
				int a = aS.pop();
				int b = aS.pop();
				int x = b + a;
				aS.push(x);
			}
			else if (si == '-')
			{
				int a = aS.pop();
				int b = aS.pop();
				int x = b - a;
				aS.push(x);
			}
			else
			{
				int num = s[i] - '0';
				aS.push(num);
			}
		}
		int r = aS.pop();
		cout << r % 10 << endl;
	}
	return 0;
}
