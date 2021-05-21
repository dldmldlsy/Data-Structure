#include<iostream>
#define NOITEM 0 //�ش� ��Ʈ���� �ѹ��� ������ �������� ����
#define ISITEM 1 //�ش� ��Ʈ���� ���� ���Ե� ����
#define AVAILABLE 2// �ش� ��Ʈ���� ������ ���� �־�����, ������ ������ ����
using namespace std;

struct Entry {
	int key;
	string value;  //��Ʈ���� value
	int valid; //��Ʈ���� ����???����
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

//class HashTable {
//	Entry* hash_table;
//	int capacity;
//	int hash_func(int key) {
//		return key % capacity;
//	}
//public:
//	HashTable(int N) {
//		capacity = N;
//		hash_table = new Entry[capacity];
//		return;
//	}
//
//	void put(int key, string value) {
//
//	}
//	void erase(int key) {
//
//	}
//	string find(int key) {
//
//	}
//
//	void put(int key, string value) {
//		int index = hash_func(key);
//		int probing = 1;
//		//��Ʈ���� ��ȿ�� �����Ͱ� ����Ǿ� ������ Ž���� ����
//		//��� �ؽ����̺��� Ž���� ������ Ž��
//		while (hash_table[index].valid == ISITEM && probing <= capacity) {
//			index = hash_func(index + 1); //���� �����
//			probing++;
//		}
//		if (probing > capacity)return; //��� �ؽ����̺� �����Ͱ� �����ϴ� ���
//		hash_table[index] = Entry(key, value);
//		return;
//	}
//
//	void erase(int key) {
//		int index = hash_func(key);
//		int probing = 1;
//
//		//��Ʈ���� ��ȿ�� �����Ͱ� ����Ǿ� �ְų�, ������ �����Ͱ� ����Ǿ��� ��Ʈ�����ٸ� Ž���� ����
//		//��� �ؽ����̺��� Ž���� ������ Ž��
//		while (hash_table[index].valid != NOITEM && probing <= capacity) {
//			if (hash_table[index].valid == ISITEM && hash_table[index].key == key) {
//				hash_table[index].erase(); //�����͸� ã���� �����ϰ� �Լ�����. 
//				return;
//			}
//			index = hash_func(index + 1);
//			probing++;
//		}
//		return; //�����͸� ã�� ���ϰ� ����� ���
//	}
//
//	string find(int key) {
//		int index = hash_func(key);
//		int probing = 1;
//		while (hash_table[index].valid != NOITEM && probing <= capacity) {
//			if (hash_table[index].valid == ISITEM && hash_table[index].key == key) {
//				return hash_table[index].value;
//			}
//			index = hash_func(index + 1);
//			probing++;
//		}
//		return "";
//	}
//
//};

//���� �ؽ̹����� �浹�� �����ϴ� �ؽ����̺�
class HashTable {
public:
	Entry* hash_table;
	int capacity;
	int divisor;

	int hash_func(int key) {
		return key % capacity;
	}
	int hash_func2(int key) {
		return divisor - (key % divisor);
	}

	void put(int key, string value) {
		int index = hash_func(key);
		int probing = 1;

		while (hash_table[index].valid == ISITEM && probing <= capacity) {
			index = hash_func(index + hash_func2(key)); //�ؤ� �ؽ̹�
			probing++;
		}
		if (probing > capacity) return;
		hash_table[index] = Entry(key, value);
		return;
	}

	void erase(int key) {
		int index = hash_func(key);
		int probing = 1;

		//��Ʈ���� ��ȿ�� �����Ͱ� ����Ǿ� �ְų�, ������ �����Ͱ� ����Ǿ��� ��Ʈ�����ٸ� Ž���� ����
//		//��� �ؽ����̺��� Ž���� ������ Ž��
		while (hash_table[index].valid != NOITEM && probing <= capacity) {
			if (hash_table[index].valid == ISITEM && hash_table[index].key == key) {
				hash_table[index].erase();
				return;
			}
			index = hash_func(index + hash_func2(key));
			probing++;
		}
		return;
	}
};

int main() {
	int t, n, m; 
	cin >> t >> n >> m;
	string oper;
	int x;
	string name;
	HashTable h;
	for (int i = 0; i < t; i++) {
		if (oper == "put") {
			cin >> x >> name;
			h.put(x, name);
		}
		else if (oper == "erase") {
			cin >> x;
			h.erase(x);
		}
	}
}