#include <iostream>
using namespace std;
class arrStack {
public:
	int* arr;
	int capacity; //배열의 크기
	int t; // top 

	arrStack(int capacity) { //스택 생성
		this->capacity = capacity;
		this->arr = new int[capacity];
		this->t = -1;//처음에 top은 -1, 하나 들어오면0됨 인덱스느낌 맨 마지막으로 들어온 원소의 인덱스=top
	}
	int size() { //배열에 있는 원소개수 
		return t + 1; //top+1
	}
	bool empty() { //비었는지 확인 
		return t == -1; //top이 -1이며 true반환
	}
	int top() {
		if (empty())return -1; //비었으면 -1반환
		else return arr[t]; // 인덱스가 t이면 top 제일 위에 있는 원소!
	}
	void push(int e) {  //e라는 원소를 넣기
		if (size() == capacity) //현재 원소개수=배열크기
			cout << "FULL" << endl; //full출력
		else arr[++t] = e; //아니면 t하나 늘려서 거기에 e대입
	}
	int pop() { //맨 위 원소 빼기 
		if (empty())return -1; //비었으면 -1출력
		return arr[t--]; //기존 top출력하고 t 하나 줄이기 맨위에 거 나갔으니까! 
	}
};
int main() {
	int t, n;
	cin >>t>> n;
	string s;
	arrStack aS(t);
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "empty") {
			cout << aS.empty() << endl;
		}
		else if (s == "top") {
			cout << aS.top() << endl;
		}
		else if (s == "push") {
			int p;
			cin >> p;
			aS.push(p);
		}
		else if (s == "pop") {
			cout<<aS.pop()<<endl;
		}
		else
			cout << "재입력바람." << endl;
	}

}
