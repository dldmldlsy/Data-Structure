#include <iostream>
using namespace std;
class Node { //노드 
	int elem; //데이터필드
	Node* next; //링크필드 

	friend class S_LinkedList; 
};

class S_LinkedList {
public:
	S_LinkedList();
	int List_size();
	bool Empty();
	void Print();
	void Append(int elem);
	int Delete(int idx);
	void Insert(int idx, int elem);
	void Min();


private:
	Node* head;
	Node* tail;
};
S_LinkedList::S_LinkedList() { // 생성자
	head = new Node; //헤드 생성
	tail = new Node; //테일 생성

	head = NULL; //널값으로 초기화 
	tail = NULL; //널값으로 초기화 
}
bool S_LinkedList::Empty() { //비었는지확인
	return (head == NULL && tail == NULL); //둘다 널값이면 true 출력
}
int S_LinkedList::List_size() { //리스트 크기 출력함수
	int list_size = 0;
	if (Empty()) {
		return list_size;
	}

	else {
		Node* cur_node = head; //현재노드를 가리키는 cur_node 생성 + 헤드로 초기화 
		while (cur_node->next != NULL) {  // 현재노트의 링크필드가 null일때까지 반복 (null일경우 tail바로 전 원소라는 뜻) 
			list_size++;
			cur_node = cur_node->next;
		}
		list_size++; //tail 
		return list_size;
	}
}
void S_LinkedList::Print() { //리스트 원소 출력함수 
	if (Empty())
		cout << "empty" << endl;
	else { 
		Node* cur_node = head;
		while (cur_node->next != NULL) {
			cout << cur_node->elem << " "; 
			cur_node = cur_node->next;
		}
		cout << cur_node->elem << endl;
	}
}
void S_LinkedList::Append(int elem) { //마지막에 원소 추가 
	Node* new_node = new Node; 
	new_node->elem = elem;
	new_node->next = NULL;

	if (Empty()) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = tail->next;
	}
	Print();
}
int S_LinkedList::Delete(int idx) { //인덱스원소 삭제하고 출력
	int removeNum = 0; //삭제될 원소값 저장하는 변수
	int cnt = 0;
	Node* cur_node;
	Node* pre_node;

	if (Empty() || List_size() <= idx) {
		return -1;
	}

	if (idx == 0) {
		if (List_size() == 1) {
			removeNum = head->elem; 
			tail = NULL;
			head = NULL;
		}
		else {
			cur_node = head;
			removeNum = cur_node->elem;
			head = cur_node->next;
		}
	}
	else {
		pre_node = cur_node = head;
		while (cnt != idx) {
			pre_node = cur_node;
			cur_node = cur_node->next;
			cnt++;
		}
		removeNum = cur_node->elem;
		pre_node->next = cur_node->next;

		if (cur_node == tail) {
			tail = pre_node;
		}
	}
	return removeNum;
}
void S_LinkedList::Insert(int idx, int elem) { 
	Node* new_node = new Node; //새 노드 생성
	new_node->elem = elem; //새 노드에 데이터필드값 저장

	Node* pre_node; 
	Node* cur_node;
	int cur_idx = 0;
	if (idx == 0) { //맨앞에 원소추가시
		if (Empty()) { 
			head = new_node;
			tail = new_node;
		}
		else {
			new_node->next = head;
			head = new_node;
		}
		Print(); 
	}
	else if (idx>List_size()) {
		cout << "Index Error" << endl;
	}
	else if (idx == List_size()) {
		Append(elem);
	}
	else {
		pre_node = cur_node = head;
		while (cur_idx != idx) {
			pre_node = cur_node;
			cur_node = cur_node->next;
			cur_idx++;
		}
		pre_node->next = new_node;
		new_node->next = cur_node;
		Print();
	}
}
void S_LinkedList::Min() {
	if (Empty())
		cout << "empty" << endl;
	else
	{
		Node* cur_node = head->next;
		int min = head->elem;
		while (cur_node->next != NULL) {
			if (min > cur_node->elem)
				min = cur_node->elem;
			cur_node = cur_node->next;
		}
		if (tail->elem < min)
			min = tail->elem;

		cout << min << endl; 
	}
}

int main() {
	int m;
	cin >> m; //테스트케이스 입력
	string n; 
	S_LinkedList sl; //단일연결리스트클래스 객체 생성
	for (int i = 0; i < m; i++) {  //테스트케이스만큼 반복
		cin >> n; //명령어 입력
		if (n == "Print") {  
			sl.Print();
		}
		else if (n == "Min") {
			sl.Min();
		}
		else if (n == "Delete") {
			int a;
			cin >> a;
			cout << sl.Delete(a) << endl;
		}
		else if (n == "Append") {
			int a;
			cin >> a;
			sl.Append(a);
		}
		else if (n == "Insert") {
			int a, b;
			cin >> a >> b;
			sl.Insert(a, b);
		}
		else
			cout << "다시 입력하세요." << endl;
	}

}
