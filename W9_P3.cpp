//�ڷᱸ�� 9���� �ǽ����� 3�� _correct
#include<iostream>
#include<vector>
using namespace std;
class isLess {
public:
	bool operator()(const int a, const int b)const {
		//int�� ���� a,b�� �Է¹޾Ƽ�
		if (a < b) {
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
		vector<int>::iterator p = v.begin(); //�ݺ��� ���� 
		isLess C; //���� ����

		if (v.empty()) { //�켱���� ť�� ������� 
			v.insert(p, e); //begin�տ� e����
		}
		else {
			while (p != v.end() && C(e, *p)) { //�ݺ��ڰ� ����Ű�� ���Һ��� e�� ���� ���
				++p; //�ݺ��� �̵�
			}
			v.insert(p, e); //p�տ� e����
		}
	}
	int min() { //���� ���� ���Ҹ� ��ȯ 
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
	cin >> t; //�׽�Ʈ���̽� �Է� 
	for (int i = 0; i < t; i++) {
		cin >> n;
		PQ pq;
		int x = 0;
		for (int j = 0; j< n; j++) {
			cin >> x;
			pq.insert(x);
		}
		pq.print();
	}
}