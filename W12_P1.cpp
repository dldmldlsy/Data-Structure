//자료구조 12주차 실습 1번 
//해시테이블 선형조사법으로 구현
//correct!

#include<iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
using namespace std;
struct Entry {
	int key;
	string value;
	int valid; 
	Entry() {
		key = 0;
		value = "";
		valid = NOITEM;
	}
	Entry(int key, string value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}
	void erase() {
		valid = AVAILABLE;
	}
};

class HashTable { //선형조사법으로 구현
	Entry* hash_table;
	int capacity;

	int hash_func(int key) {
		return key % capacity;
	}
public:
	HashTable(int N) {
		capacity = N;
		hash_table = new Entry[capacity];

	}
	
	void put(int key, string value) {
		int index = hash_func(key);
		int probing = 1;
		while (hash_table[index].valid == ISITEM && probing <= capacity) {
			index = hash_func(index + 1);
			probing++;
		}
		if (probing > capacity)return;
		hash_table[index] = Entry(key, value);
		cout << probing << endl;
		return;
	}

	void erase(int key) {
		int index = hash_func(key);
		int probing = 1;
		while (hash_table[index].valid != NOITEM && probing <= capacity) {
			if (hash_table[index].valid == ISITEM&&hash_table[index].key==key) {
				hash_table[index].erase();
				return;
			}
			index = hash_func(index + 1);
			probing++;
		}
		cout << "None" << endl;
		return;
	}
	
	string find(int key) {
		int index = hash_func(key);
		int probing = 1;
		while (hash_table[index].valid != NOITEM && probing <= capacity) {
			if (hash_table[index].valid == ISITEM && hash_table[index].key == key) {
				return hash_table[index].value;
			}
			index = hash_func(index + 1);
			probing++;
		}
		return "None";
	}
};

int main() {
	int t, n;  //명령어개수, 해시테이블 크기, 해시함수에 사용할 정수(n,m은 서로소임이 보장)
	cin >> t >> n;
	string oper;
	int x;
	string name;
	HashTable h(n);
	for (int i = 0; i < t; i++) {
		cin >> oper;
		if (oper == "put") {
			cin >> x >> name;
			h.put(x, name);
		}
		else if (oper == "erase") {
			cin >> x; 
			h.erase(x);
		}
		else if (oper =="find") {
			cin >> x;
			cout << h.find(x) << endl;
		}
		else {
			cout << "다시" << endl;
		}
	}
}
