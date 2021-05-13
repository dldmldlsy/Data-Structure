//자료구조실습 10주차 2번
//최소힙 심화
//correct! 
//계산 횟수와 힙출력

#include<iostream>
#include<string>
#include<vector>

using namespace std;
enum direction { MIN = 1, MAX = -1 };

class Heap {
private:
	vector<int> v;
	int heap_size;
	int root_index;
	int direction;

public:
	Heap(int direction) {
		v.push_back(-1);
		this->heap_size = 0;
		this->root_index = 1;
		this->direction = direction;
	}

	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}
	void upHeap(int idx) {
		if (idx == root_index)return;
		else {
			int parent = idx / 2;
			if (v[parent] * direction > v[idx] * direction) {
				swap(parent, idx);
				upHeap(parent);
			}
		}
	}

	void downHeap(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= heap_size) {
			if (v[left] * direction <= v[right] * direction) {
				if (v[left] * direction < v[idx] * direction) {
					swap(left, idx);
					downHeap(left);
				}
				else return;
			}
			else {
				if (v[right] * direction < v[idx] * direction) {
					swap(right, idx);
					downHeap(right);
				}
				else return;
			}
		}
		else if (left <= heap_size) {
			if (v[left] * direction < v[idx] * direction) {
				swap(left, idx);
				downHeap(left);
			}
			else return;
		}
		else return;
	}

	void insert(int e) {
		v.push_back(e);
		heap_size++;
		upHeap(heap_size);
	}

	int pop() {
		if (heap_size == 0) {
			return -1;
		}
		int top = v[root_index];
		v[root_index] = v[heap_size];
		heap_size--;
		v.pop_back();
		downHeap(root_index);
		return top;

	}

	int top() {
		if (isEmpty()) {
			return -1;
		}
		return v[root_index];
	}
	int size() {
		return heap_size;
	}
	bool isEmpty() { return heap_size == 0; }

	void print() {
		if (isEmpty()) {
			cout << -1 << endl;
			return;
		}
		else {
			for (int i = 1; i <= heap_size; i++) {
				cout << v[i] << " ";
			}
			cout << endl;

		}
	}
};
int main() {
	int T;
	cin >> T;// test case 주어짐. 
	int N, P, k;
	for (int i = 0; i < T; i++) {
		Heap heapPQ(MIN); //최소힙 생성
		cin >> N >> P; //N, P입력받기
		for (int j = 0; j < N; j++) { //N번 반복 
			cin >> k;//물질의 온도값입력받음
			heapPQ.insert(k); //최소힙에 삽입->오름차순으로 정렬됨. 
		}
		// 힙에 n개의 온도k값들이 정렬되어있음. 
		//이중 제일 작은 게 기준 P보다 작은지 판단.
		int min1, min2, count = 0;
		while (heapPQ.top() < P) {
			if (heapPQ.size() == 1 && heapPQ.top() < P) {
				break;
			}
			min1 = heapPQ.pop();
			min2 = heapPQ.pop();
			heapPQ.insert((min1 + min2) / 2);
			count++;
		}
		if (heapPQ.size() == 1 && heapPQ.top() < P) {
			cout << "False" << endl;
		}
		else {
			cout << count << endl;
			heapPQ.print();
		}
	}
}