//자료구조 10주차 실습 1번 (최대힙) 
//correct!
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
	Heap heapPQ(MAX);
	int t;
	cin >> t;
	string n;
	int a;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n == "isEmpty") {
			cout << heapPQ.isEmpty() << endl;
		}
		else if (n == "insert") {
			cin >> a;
			heapPQ.insert(a);
		}
		else if (n == "size") {
			cout << heapPQ.size() << endl;
		}
		else if (n == "pop") {
			cout << heapPQ.pop() << endl;
		}
		else if (n == "top") {
			cout << heapPQ.top() << endl;
		}
		else if (n == "print") {
			heapPQ.print();
		}
		else {
			cout << "다시" << endl;
		}
	}
}