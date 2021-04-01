//링크드 리스트를 이용해 구현 

#include <iostream>
using namespace std;
class Node { // 노드클래스 생성 
public:
	int data; //데이터필드 
	Node* next; //링크필드

	Node(int e) { //노드클래스 생성자 (객체 생성시 자동 동작) 
		this->data = e; // 인수값을 해당 클래스객체의 데이터필드에 저장
		this->next = NULL; // 다음 노드를 가리키는 링크필드값은 null값으로 두기 
	}
};
class linkedStack { //링크드리스트를 이용한 스택 클래스
public:
	Node* head; //첫 노드를 가리킬 헤드포인터
	Node* tail; //마지막 노드를 가리킬 테일 포인터
	int n; // 스택의 size를 저장할 변수
	linkedStack() { // 디폴트생성자 
      // 헤드와 테일을 null로 초기화 
		this->head = NULL; 
		this->tail = NULL;
		this->n = 0; //스택크기 0으로 초기화
	}
	int size() { // 스택크기 반환하는 메서드
		return n; // n반환
	}
	bool empty() { // 공란인지확인하는 메서드
		return n == 0; // 스택크기를 뜻하는 n이 0이면 true를 반환
	}
	int top() { // top (꼭대기 원소)의 데이터를 반환하는 메서드
		if (empty())return -1; // 스택이 비어있으면 -1 반환
		else return head->data; // 비어있지않으면 top인 첫 노드의 데이터값을 반환한다. 
	}
	void push(int e) { //스택에 데이터를 추가하는 push 메서드, 새 데이터값= e
		Node* newNode = new Node(e); // 새로운 노드를 생성. 
		if (empty()) { // 스택이 비어있다면 새 노드가 첫번째이자 마지막 노드이므로 
			head = tail = newNode; // 헤드와 테일에 새 노드를 저장
			n++; // 스택 크기 +1
		}
		else { //비어있지않다면 새 노드는 맨앞원소 앞에 추가되므로 헤드가 새 노드로 바뀜
			newNode->next = head; // 새 노드의 다음차례 노드를 저장하는 링크필드에 기존 헤드가 저장됨 
			head = newNode; // 헤드는 새노드를 가리킴.
			n++; // 스택 크기 +1
		}
	}
	int pop() { // 제일 위에 있는 (마지막으로 들어간) 원소를 꺼내는 메서드
		if (empty()) return -1; // 비어있으면 -1 반환
		else { // 비어있지않으면
			Node* temp = head; //노드를 가리키는 포인터 변수 temp에 포인터변수 head 저장.  포인터 변수 temp가 head가 가리키는 기존의 첫번째 노드를 가리키게 된다. 
                             // 첫번째노드를 스택에서 빼내고 두번째원소가 head가 될 건데 후에 이를 반환해야하기때문에 이 노드를 가리키는 다른 포인터변수를 미리 만드는 것.
			head = head->next;  // 포인터변수 head는 기존헤드의 다음 노드를 가리킴. 
			n--; // top이 pop되었으므로  스택 크기 -1
			return temp->data; // 맨앞에 있던 노드를 가리키는 temp를 통해 맨 앞 노드의 데이터값을 반환하도록 함. 
		}
	}
};
int main() {
	int n; // 테스트케이스를 저장할 변수
	cin >> n; // 테스트케이스 입력
	string s; // 명령어를 담는 변수 선언
	linkedStack aS; // 스택클래스의 객체 aS 생성 ( 생성자가 동작해서 head, tail은 null, 스택size는0으로 초기화됨) 

	for (int i = 0; i < n; i++) { //테스트케이스 수 만큼 반복
		cin >> s; // 명령어 입력 
		if (s == "empty") {  
			cout << aS.empty() << endl; //반환형이 있는 함수기때문에 cout을 통해 반환값을 출력시킴.
		}
		else if (s == "top") {  
			cout << aS.top() << endl;//반환형이 있는 함수기때문에 cout을 통해 반환값을 출력시킴.
		}
		else if (s == "push") {
			int p;
			cin >> p; //push 할 데이터값입력 push함수의 인자
			aS.push(p);
		}
		else if (s == "pop") {
			cout << aS.pop() << endl; //반환형이 있는 함수기때문에 cout을 통해 반환값을 출력시킴.
		}
		else
			cout << "재입력바람." << endl;
	}

}

//#include <iostream>
//using namespace std;
//class arrStack {
//public:
//	int* arr;
//	int capacity; //배열의 크기
//	int t; // top 
//
//	arrStack(int capacity) { //스택 생성자 (수용가능 크기를 인수로받기) 
//		this->capacity = capacity;
//		this->arr = new int[capacity];
//		this->t = -1;//처음에 top은 -1, 하나 들어오면0됨 인덱스느낌 맨 마지막으로 들어온 원소의 인덱스=top
//	}
//	int size() { //배열에 있는 원소개수 
//		return t + 1; //top+1
//	}
//	bool empty() { //비었는지 확인 
//		return t == -1; //top이 -1이며 true반환
//	}
//	int top() {
//		if (empty())return -1; //비었으면 -1반환
//		else return arr[t]; // 인덱스가 t이면 top 제일 위에 있는 원소!
//	}
//	void push(int e) {  //e라는 원소를 넣기
//		if (size() == capacity) //현재 원소개수=배열크기
//			cout << "FULL" << endl; //full출력
//		else arr[++t] = e; //아니면 t하나 늘려서 거기에 e대입
//	}
//	int pop() { //맨 위 원소 빼기 
//		if (empty())return -1; //비었으면 -1출력
//		return arr[t--]; //기존 top출력하고 t 하나 줄이기 맨위에 거 나갔으니까! 
//	}
//};
//int main() {
//	int n;
//	cin >> n;
//	string s;
//	arrStack aS(1000);
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		if (s == "empty") {
//			cout << aS.empty() << endl;
//		}
//		else if (s == "top") {
//			cout << aS.top() << endl;
//		}
//		else if (s == "push") {
//			int p;
//			cin >> p;
//			aS.push(p);
//		}
//		else if (s == "pop") {
//			cout<<aS.pop()<<endl;
//		}
//		else
//			cout << "재입력바람." << endl;
//	}
//
//}



