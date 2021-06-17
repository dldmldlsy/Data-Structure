//자료구조실습 11주차 3번 
//이진탐색트리 생성 후 오름차순으로 값출력
//correct!

#include<iostream>
using namespace std;
class Node {
private:
	int data;
	Node* par;
	Node* left;
	Node* right;
public:
	Node(int data) {
		this->data = data;
		this->par = NULL;
		this->left = NULL;
		this->right = NULL;
	}
	void setLeft(Node* node) {
		if (node == NULL) {
			this->left =NULL;
		}
		else { this->left = node; node->par = this; }
	}
	void setRight(Node* node) {
		if (node == NULL) {
			this->right = NULL;
		}
		else {
			this->right = node;  node->par = this;
		}
	}
	friend class BST;
};
class BST {
public:
	Node* root;
public: 
	BST() {
		this->root = NULL;
	}
	Node* search(int data) {
		Node* curN = this->root;
		while (curN != NULL) {
			if (data = curN->data) {
				return curN;
			}
			else if (data > curN->data) {
				curN = curN->right;
			}
			else
				curN = curN->left;
		}
		return NULL;
	}
	void insert(int data) {
		Node* node = new Node(data);
		if (this->root == NULL) { this->root = node; return; }
		Node* parN = NULL;
		Node* curN = this->root;
		while (curN != NULL) {
			if (data > curN->data) {
				parN = curN;
				curN = curN->right;
			}
			else {
				parN = curN;
				curN = curN->left;
			}
		}
		if (data > parN->data) {
			parN->setRight(node);
		}
		else if (data < parN->data) {
			parN->setLeft(node);
		}
	}

	void remove(int data) {
		Node* node = this->search(data); //지울 노드 탐색. 
		Node* parN = node->par; //지울 노드의 부모. (지울노드의 자식들을 이 부모의 자식으로 넣어줄 거.) 
		if (node->left == NULL && node->right == NULL) {

		}

	}
	void inorder(Node* node) {
		if (node == NULL) return;
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}
};
int main() {
	int t;
	int n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n; int x; BST bst;
		for (int j = 0; j < n; j++) {
			cin >> x; bst.insert(x);
		}
		bst.inorder(bst.root);
		cout << endl;
	}
}