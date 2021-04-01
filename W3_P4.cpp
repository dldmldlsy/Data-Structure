////3주차 4번문제 

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
	int n; // 테스트케이스 변수 선언
	cin >> n; //테스트케이스 수 입력받음
	string s; //명령어 변수 선언
	for (int i = 0; i < n; i++) {
		cin >> s; // 명령어 입력
		int size = s.size(); // size()함수를 이용해 문자열 s의 길이를 구해 size변수에 저장. 
		linkedStack aS; //스택 클래스 객체 생성.
		for (int i = 0; i < size; i++) { //문자열길이만큼 반복 
			char si = s.at(i); // 문자열s의 원소를 si에 저장  si=s[0], s[i], ... 
			if (si == '*') // 곱셈연산의 경우 
			{
				// 두개의 피연산자가 필요하므로 pop()를 이용해 두개의 피연산자를 가져온다. 
				int b = aS.pop(); // pop함수를 이용해 스택 맨위의 top을 반환해서 a에 저장 
				int a = aS.pop(); // 두번째에 있던 값이 top이 되고 그 top을 또 반환해서 b에 저장 
				int x =a * b; // 두 값을 곱함.
				aS.push(x);
			}
			else if (si == '+') // 덧셈연산
			{    
				int b = aS.pop(); 
				int a = aS.pop();
				int x = a + b; 
				aS.push(x);
			}
			else if (si == '-')
			{   // ab-=> a-b : 스택에 a-> b(top) 으로 저장되어있을테니 
				int b = aS.pop(); 
				int a = aS.pop();
				int x = a - b; //먼저 pop한 게 연산자 오른쪽 에 위치한다. 
				aS.push(x);
			}
			else //연산자가 아닌 경우
			{
				int num = s[i] - '0';  // 문자열로 저장된 숫자를 int형으로 바꿔줌. 
				aS.push(num); // 스택에 해당 숫자를 저장. 
			}
		}
		cout << aS.pop() << endl; // 명령어를 다 처리한 후에 저장된 마지막 수를 pop한다. 
	}
	return 0; 
}


////배열을 이용해 후위표기법 연산 수행 프로그램구현
//#include <iostream>
//using namespace std;
//class arrStack {
//public:
//	int* arr;
//	int capacity; //배열의 크기
//	int t; // top 
//
//	arrStack(int capacity) { //스택 생성
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
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		int size = s.size();
//		arrStack aS(size);
//		for (int i = 0; i < size; i++) {
//			char si = s.at(i);
//			if (si == '*')
//			{
//				int a = aS.pop();
//				int b = aS.pop();
//				int x = b * a;
//				aS.push(x);
//			}
//			else if (si == '+')
//			{
//				int a = aS.pop();
//				int b = aS.pop();
//				int x = b + a;
//				aS.push(x);
//			}
//			else if (si == '-')
//			{
//				int a = aS.pop();
//				int b = aS.pop();
//				int x = b - a;
//				aS.push(x);
//			}
//			else
//			{
//				int num = s[i] - '0';
//				aS.push(num);
//			}
//		}
//		cout << aS.pop() << endl;
//	}
//	return 0; 
//}