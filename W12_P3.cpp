////자료구조 12주차 실습 3번
////해시테이블 이중해시법으로 구현
////correct!
//#include<iostream>
//#define NOITEM 0 //해당 엔트리에 한번도 삽입이 되지않은 상태
//#define ISITEM 1 //해당 엔트리에 값이 삽입된 상태
//#define AVAILABLE 2// 해당 엔트리에 이전에 값이 있었으나, 지금은 지워진 상태
//using namespace std;
//
//struct Entry {
//	int key;
//	string value;  //엔트리의 value
//	int valid; //엔트리의 생태???변수
//	Entry() {
//		key = 0;
//		value = "";
//		valid = NOITEM;
//	}
//
//	Entry(int key, string value) {
//		this->key = key;
//		this->value = value;
//		valid = ISITEM;
//	}
//	void erase() {
//		valid = AVAILABLE;
//	}
//};
//
//
////더블 해싱법으로 충돌을 관리하는 해시테이블
//class HashTable {
//	Entry* hash_table;
//	int capacity;
//	int divisor;
//
//	int hash_func(int key) {
//		return key % capacity;
//	}
//	int hash_func2(int key) {
//		return divisor - (key % divisor);
//	}
//	public:
//	HashTable(int N, int m) {
//		capacity = N;
//		divisor = m;
//		hash_table = new Entry[capacity];
//		return; //이거 꼮 필요한가?
//	}
//
//	void put(int key, string value) {
//		int index = hash_func(key);
//		int probing = 1;
//
//		while (hash_table[index].valid == ISITEM && probing <= capacity) {
//			index = hash_func(index + hash_func2(key)); //이중해싱법
//			probing++;
//		}
//		if (probing > capacity) return;
//		hash_table[index] = Entry(key, value);
//		cout << probing << endl;
//		return;
//	}
//
//	void erase(int key) {
//		int index = hash_func(key);
//		int probing = 1;
//
//		//엔트리에 유효한 데이터가 저장되어 있거나, 이전에 데이터가 저장되었던 엔트리였다면 탐색을 지속
////		//모든 해시테이블을 탐색할 때까지 탐색
//		while (hash_table[index].valid != NOITEM && probing <= capacity) {
//			if (hash_table[index].valid == ISITEM && hash_table[index].key == key) {
//				hash_table[index].erase();
//				return;
//			}
//			index = hash_func(index + hash_func2(key));
//			probing++;
//		}
//		//찾지 못하면
//		cout << "None" << endl; //None출력
//		return; //함수종료
//	}
//	string find(int key) {
//		int index = hash_func(key);
//		int probing=1;
//		while (hash_table[index].valid != NOITEM && probing <= capacity) {
//			if (hash_table[index].valid == ISITEM && hash_table[index].key == key) {
//				return hash_table[index].value;
//			}
//			index = hash_func(index+ hash_func2(key));
//			probing++;
//		}
//		return "None";
//	}
//};
//
//int main() {
//	int t, n, m;  //명령어개수, 해시테이블 크기, 해시함수에 사용할 정수(n,m은 서로소임이 보장)
//	cin >> t >> n >> m;
//	string oper;
//	int x;
//	string name;
//	HashTable h(n,m);
//	for (int i = 0; i < t; i++) {
//		cin >> oper;
//		if (oper == "put") {
//			cin >> x >> name;
//			h.put(x, name);
//		}
//		else if (oper == "erase") {
//			cin >> x;
//			h.erase(x);
//		}
//		else if (oper == "find") {
//			cin >> x;
//			cout<<h.find(x) << endl;
//		}
//		else {
//			cout << "다시" << endl;
//		}
//	}
//}