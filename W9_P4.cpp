//자료구조 9주차 실습문제 4번 _correct
#include<iostream>
#include<vector>
using namespace std;
class isLess {
public:
	bool operator()(const int a, const int b)const {
		//int형 정수 a,b를 입력받아서
		if (a>b) {
			return true;
		}
		else {
			return false;
		}
	}
};
class PQ {
private:
	vector<int>v;
public:
	int size() {
		return v.size();
	}
	bool empty() {
		return v.size() == 0;
	}
	void insert(int e) {
		vector<int>::iterator p = v.begin(); //반복자 선언 
		isLess C; //비교자 선언

		if (v.empty()) { //우선순위 큐가 비었으면 
			v.insert(p, e); //begin앞에 e삽입
		}
		else {
			while (p != v.end() && C(e, *p)) { //반복자가 가리키는 원소보다 e가 작은 경우
				++p; //반복자 이동
			}
			v.insert(p, e); //p앞에 e삽입
		}
	}
	int min() { //가장 작은 원소를 반환 
		return v.back(); //
	}
	void removeMin() {
		v.pop_back();
	}
	void print() {
		for (vector<int>::iterator iter = --v.end(); iter != v.begin(); --iter) {
			cout << *iter << ' ';
		}
		cout << *v.begin() << endl;
	}
};
int main() {
	int t, n;
	cin >> t; //테스트케이스 입력 
	for (int i = 0; i < t; i++) {
		cin >> n;
		PQ pq;
		int x = 0;
		for (int j = 0; j < n; j++) {
			cin >> x;
			pq.insert(x);
		}
		pq.print();
	}
}