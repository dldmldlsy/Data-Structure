//자료구조실습 11주차 1번 
//이진탐색트리 생성 후 m번째 작은 값출력
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
		if (node == NULL) { this->left = NULL; }
		else {	this->left = node; node->par = this;}
	}
	void setRight(Node* node) {
		if (node == NULL) { this->right = NULL; }
		else{this->right = node; node->par = this;}
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
			if (data == curN->data) {
				return curN;
			}else if (data > curN->data) {
				curN = curN->right;
			}
			else {
				curN = curN->left;
			}
		}
		return NULL;
	}
	void insert(int data) {
		Node* node = new Node(data);
		if (this->root == NULL) {this->root = node; return;}

		Node* parN = NULL;
		Node* curN = this->root;
		while (curN != NULL) {
			if (data > curN->data) {
				parN = curN; curN = curN->right;
			}
			else { parN = curN; curN = curN->left; }
		}
		if (data > parN->data) { parN->setRight(node); }
		else if (data < parN->data) { parN->setLeft(node); }
	}
	int min= 0;
	void solution(Node* node, int num) {
		if (node == NULL) return;
		solution(node->left, num);
		min++;
		if (min == num) { cout << node->data << endl; return; }
		solution(node->right, num);
	}
};
int main() {
	int t;
	cin >> t;
	int n;
	int min_num;
	for(int i = 0; i < t; i++) {
		cin >> n; int x; BST bst;
		for (int j = 0; j < n; j++) {
			cin >> x; bst.insert(x);
		}
		cin>>min_num;
		bst.solution(bst.root, min_num);
	}
}