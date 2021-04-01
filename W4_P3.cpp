//#include <iostream>
//using namespace std;
//class arrq { //배열로 구현한 원형큐클래스
//private:
//	int* q; //정수형변수를 가리킬 포인터 큐 
//	int rear; //마지막 
//	int front;// 맨앞 
//	int capacity;//큐의 크기 
//
//public:
//	arrq(int capacity) { //생성자 (
//		this->capacity = capacity + 1; //원형큐이므로, 셀이 하나 더 필요  (왜 원형큐니까 하나가 더 필요한가!!) 
//		q = new int[this->capacity];  // 삽입할 원소수 +1 만큼 공간할당 
//		front = rear = 0; //처음엔 인덱스 0번에서 둘다 시작.
//
//		for (int i = 0; i < capacity; i++) {
//			q[i] = 0; //다 0으로 초기화 
//		}
//	}
//	void enqueue(int value) { // rear에 삽입! 
//		if (isfull()) { //배열이 꽉찼다면
//			cout << "Full" << endl; //full출력
//		}
//		else {
//			rear = (rear + 1) % capacity;  //rear를 오른쪽으로 이동
//			q[rear] = value; //rear에 값 입력
//		}
//	}
//
//	void dequeue() {
//		if (isempty()) // 배열이 비어있다면 
//			cout << "empty" << endl; //empty출력
//		else {
//			cout << q[front+1] << endl;
//			front = (front + 1) % capacity;//front를 오른쪽으로 이동
//			q[front] = 0; //
//		}
//	}
//	void _front() {
//		if (isempty())cout << "empty" << endl;
//		else cout << q[(front + 1) % capacity] << endl; //front 오른쪽값 출력
//	}
//	void _rear() {
//		if (isempty())cout << "empty" << endl;
//		else cout << q[rear] << endl;
//	}
//	int size() { //현재까지 저장된 값의 개수
//		return (rear - front + capacity) % capacity; //왜 rear-front가 아닌지 (ex. 1-5=-4(x) 1-5+7=3(0)
//	}
//
//	bool isfull() {
//		return front == (rear + 1) % capacity;
//	}
//	bool isempty() {
//		return front == rear;
//	}
//};
//int main() {
//	int n, t;
//	cin >> n >> t;
//	arrq aq(n);
//	string s;
//	int a;
//	for (int i = 0; i < t; i++) {
//		cin >>s ;
//		if (s == "isEmpty") {
//			cout<<boolalpha<<aq.isempty()<<endl; //true로 출력되는데 문제출력창은 True ! =>통과됨.
//		}
//		else if (s == "size") {
//			cout<<aq.size()<<endl;
//		}
//		else if (s == "dequeue") {
//			aq.dequeue();
//		}
//		else if (s == "enqueue") {
//			cin >> a;
//			aq.enqueue(a);
//		}
//		else if (s == "front") {
//			aq._front();
//		}
//		else if (s == "rear") {
//			aq._rear();
//		}
//		else
//			cout << "다시 입력해주세요." << endl;
//
//
//	}
//}