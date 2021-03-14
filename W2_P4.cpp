#include <iostream>
using namespace std;
class Node {
	int data;
	Node* pre;
	Node* next;

	friend class D_LinkedList;
};
class D_LinkedList {
public:
	D_LinkedList();
	void Print();
	void Append(int x);
	int Delete(int idx);
	void Print_reverse();
	void Sum();

private:
	int listSize;
	Node* head;
	Node* tail;
};
D_LinkedList::D_LinkedList() {
	listSize = 0;

	//head = new Node;
	//tail = new Node;

	head = NULL;
	tail = NULL;
}
void D_LinkedList::Print() {
	if (listSize == 0) {
		cout << "empty" << endl;
		return;
	}

	Node* cur_node = head;
	while (cur_node->next != NULL) {
		cout << cur_node->data << " ";
		cur_node = cur_node->next;
	}
	cout << cur_node->data << endl;
}
void D_LinkedList::Append(int x) {
	Node* newNode = new Node();
	newNode->data = x;

	if (listSize == 0) {
		head = newNode;
		tail = newNode;
		listSize++;
		Print();
		return;
	}
	
	newNode->pre = tail;
	newNode->next = NULL;

	tail->next = newNode;
	tail = tail->next;
	listSize++;
	Print();
}
int D_LinkedList::Delete(int idx) {
	if (listSize == 0 || listSize <= idx) {
		return -1;
	}
	if (listSize == 1) {
		int num = head->data;
		head = NULL;
		tail = NULL;
		listSize--;
		return num;
	}
	Node* cur_node = head;
	//헤드 삭제시
	if (idx == 0) {
		int num = head->data;
		head = head->next;
		listSize--;
		return num;
	}

	//일반적인경우
	for (int i = 0; i < idx; i++) {
		cur_node = cur_node->next;
	}
	//테일삭제시
	if (idx == (listSize - 1)) {
		int num = tail->data;
		cur_node->pre->next = NULL;
		tail = cur_node->pre;
		listSize--;
		return num;
	}

	cur_node->pre->next = cur_node->next;
	cur_node->next->pre = cur_node->pre;
	listSize--;
	return cur_node->data;
}
void D_LinkedList::Print_reverse() {
	if (listSize == 0) {
		cout << "empty" << endl;
		return;
	}

	Node* cur_node = tail;
	while (cur_node->pre != NULL) {
		cout << cur_node->data << " ";
		cur_node = cur_node->pre;
	}
	cout << cur_node->data <<endl;
}
void D_LinkedList::Sum() {
	int sum = 0;

	Node* cur_node = head;
	while (cur_node != NULL) {
		sum += cur_node->data;
		cur_node = cur_node->next;
	}
	cout << sum << endl;
}
int main() {
	int m;
	cin >> m; //테스트케이스 입력
	string n;
	D_LinkedList sl; //단일연결리스트클래스 객체 생성
	for (int i = 0; i < m; i++) {  //테스트케이스만큼 반복
		cin >> n; //명령어 입력
		if (n == "Print") {
			sl.Print();
		}
		else if (n == "Append") {
			int a;
			cin >> a;
			sl.Append(a);
		}
		else if (n == "Delete") {
			int a;
			cin >> a;
			cout << sl.Delete(a) << endl;
		}
		else if (n == "Print_reverse") {
			sl.Print_reverse();
		}
		else if (n == "Sum") {
			sl.Sum();
		}
		else
			cout << "다시 입력하세요." << endl;
	}
	return 0;
}