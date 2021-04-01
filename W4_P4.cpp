//#include <iostream>
//#include <string>
//using namespace std;
//
//class node {
//public:
//	int data;
//	node* next;
//	node(int data) {
//		this->data = data;
//		this->next = NULL;
//	}
//};
//class linkedlist {
//public:
//	node* front;
//	node* rear;
//
//	linkedlist() { //생성자 
//		//front rear NULL로 초기화
//		this->front = NULL;
//		this->rear = NULL;
//	}
//	void addend(int data) { //리스트 뒤에 추가하는 함수
//		node* newnode = new node(data); //새 노드 생성
//		if (front == NULL) //front가 null이면 노드가 비어있다는 뜻
//			front = rear = newnode; //새 노드가 front이자 rear가 됨
//		else { //빈 리스트가 아닐경우
//			rear->next = newnode; //맨뒤노드 rear의 링크필드가 새 노드를 가리키게 하기( 맨뒤에 매달았음!) 
//			rear = newnode; //rear(맨 마지막 노드를 가리키느 포인터)를 새 노드로 설정! 
//		} 
//	}
//	void removefront() { //맨 앞 노드를 삭제하는 함수
//		if (front != NULL) { //리스트가 비어있지않으면  (비어있는 경우는 아래 dequeue함수에서 empty출력하도록 해둠 )
//			node* tmp = front; //새 노드하나 만들어서 새 노드에 기존 front를 저장해둠 (tmp에는 현재 맨 앞노드의 정보 저장) 
//			front = front->next; //맨 앞 노드를 가리키는 front노드가 기존 두번째 노드를 가리키게 함
//			                     //(이제 두번째 노드가 맨앞노드가 되는 거->자동으로 기존 맨앞노드는 리스트에서 떨어짐) 
//			delete tmp; //tmp 메모리 해제 
//		} 
//	}
//};
//
//class linkedqueue {
//public:
//	linkedlist* q; //연결리스트를 가리키는 포인터 q
//	int n; //큐 원소개수
//
//	linkedqueue() { //연결리스트큐 생성자
//		this->q = new linkedlist(); // 연결리스트 객체 생성
//		this->n = 0; //원소수 0으로 초기화
//	}
//	int size() { //원소 수(리스트크기) 구하는 함수
//		return n;
//	}
//	bool isempty() { //비었는지 
//		return n == 0; //n이 0이면 원소가 없으니까 비었다는 뜻=> true반환
//	}
//	void front() { //front 
//		if (isempty()) //큐가 비어있으면 
//			cout << "empty" << endl; //empty출력
//		else
//			cout<<(q->front->data)<<endl; 
//		//q의 front 의 데이터 출력
//	}
//	void rear() { //rear
//		if (isempty())cout << "empty" << endl; //비었으면 empty출력
//		else cout << q->rear->data << endl; //rear의 data출력 
//	}
//	void enqueue(int e) { //삽입(맨뒤에 삽입) 
//		q->addend(e); //뒤에 원소추가하는 addend (포인터q가 가리키는 객체의 멤버함수)호출
//		n++;
//	}
//	void dequeue() { //삭제 (맨앞 거 삭제) 
//		if (isempty()) cout << "empty" << endl; //비었으면 empty 출력 (삭제할 게 없음) 
//		else {
//			q->removefront(); //앞에거 없는 removefront함수 호출 
//			n--; //원소개수 하나 줄이기 
//		}
//	}
//};
//int main() {
//	int t;
//	cin >> t; //테스트 케이스 입력
//	
//	for (int i = 0; i < t; i++) { //테스트케이스만큼 반복
//		int n; // 카드개수 (변수선언 여기서하는 거 맞나????->맞대!) 
//		cin >> n;  //카드개수 입력받음
//		linkedqueue aQ; //P1 카드들 (데이터값=캐릭터체력) 
//		linkedqueue bQ; //P2 카드들 
//		
//		for (int j = 0; j < n; j++) { //카드 개수 만큼 반복
//			int x; 
//			cin >> x; //체력을 입력받아서 
//			aQ.enqueue(x); //큐에 넣음. 
//		} //P1의 체력이 주어짐
//		for (int m = 0; m < n; m++) { //카드 개수 n만큼 반복
//			int y; 
//			cin >> y; //체력을 입력받아서 
//			bQ.enqueue(y); //큐에 넣음
//		} //P2의 체력이 다 주어짐. 
//
//		int asum = 0, bsum = 0; //P1의 승점, P2의 승점
//		int  r, afd, bfd; //r: 체력차, 겨룰 p1의 체력, 겨룰 p2의 체력
//		for (int k = 0; k < n; k++) {
//			afd = aQ.q->front->data; //front의 데이터=승부할 체력
//			bfd = bQ.q->front->data;
//			r = abs(afd - bfd); //두 체력의 차이크기 (절댓값)
//			if (afd > bfd) { //P1의 체력이 더 큰 경우
//				asum++; //P1의 승점+1
//				bQ.q->front->next->data += r; 
//				//두 체력의 차를 승부에서 진 P2의 두번째데이터값(다음에 겨룰 값)에 더해줌
//			}
//			else if (afd < bfd) { //P2가 이길 경우!
//				bsum++;
//				aQ.q->front->next->data += r;
//			}
//
//			//승부한 체력은 없애준당
//			aQ.dequeue();
//			bQ.dequeue();
//		}
//
//		if (asum > bsum) { cout << asum << endl; } //P1의 승점이 더 큰 경우 P1의 승점 출력
//		else { cout << bsum << endl; } //P2가 더 크거나 비겼을 경우 P2의 승점출력)
//	}
//	return 0;
//}