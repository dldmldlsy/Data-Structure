//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//enum direction {MIN=1,MAX=-1};
//
//class Heap {
//private:
//	vector<int> v;
//	int heap_size;
//	int root_index;
//	int direction;
//
//public:
//	Heap(int direction) {
//		v.push_back(-1);
//		this ->heap_size = 0;
//		this->root_index = 1;
//		this->direction = direction;
//	}
//
//	void swap(int idx1, int idx2) {
//		v[0] = v[idx1];
//		v[idx1] = v[idx2];
//		v[idx2] = v[0];
//	}
//	void upHeap(int idx) {
//		if (idx == root_index)return;
//		else {
//			int parent = idx / 2;
//			if (v[parent] * direction > v[idx] * direction) {
//				swap(parent, idx);
//				upHeap(parent);
//			}
//		}
//	}
//
//	void downHeap(int idx) {
//		int left = idx * 2;
//		int right = idx * 2 + 1;
//		if (right <= heap_size) {
//			if (v[left] * direction <= v[right] * direction) {
//				if (v[left] * direction < v[idx] * direction) {
//					swap(left, idx);
//					downHeap(left);
//				}
//				else return;
//			}
//			else {
//				if (v[right] * direction < v[idx] * direction) {
//					swap(right, idx);
//					downHeap(right);
//				}
//				else return;
//			}
//		}
//		else if (left <= heap_size) {
//			if (v[left] * direction < v[idx] * direction) {
//				swap(left, idx);
//				downHeap(left);
//			}
//			else return;
//		}
//		else return;
//	}
//
//	void insert(int e) {
//		v.push_back(e);
//		heap_size++;
//		upHeap(heap_size);
//	}
//	 
//	int pop() {
//		int top = v[root_index];
//		v[root_index] = v[heap_size];
//		heap_size--;
//		v.pop_back();
//		downHeap(root_index);
//		return top;
//
//	}
//
//	int top() { return v[root_index]; }
//	int size() {
//		return heap_size;
//	}
//	bool isEmpty() { return heap_size == 0; }
//};
//int main() {
//	Heap heapPQ(MAX);
//	cout << boolalpha << heapPQ.isEmpty() << endl;
//	heapPQ.insert(3);
//	heapPQ.insert(7);
//	heapPQ.insert(11);
//	cout << heapPQ.top() << endl;
//	heapPQ.insert(2);
//	heapPQ.insert(15);
//	heapPQ.insert(5);
//	cout << heapPQ.top() << endl;
//	cout << heapPQ.size() << endl;
//	heapPQ.insert(8);
//	cout << heapPQ.pop() << endl;
//	cout << heapPQ.pop() << endl;
//	cout << heapPQ.pop() << endl;
//	cout << heapPQ.size() << endl;
//	cout << boolalpha << heapPQ.isEmpty() << endl;
//}