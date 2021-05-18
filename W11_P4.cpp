#include<iostream>
using namespace std;
class Node {
private:
	int data;
	Node* par;
	Node* left;
	Node* right;

public: Node(int data) {
	this->data = data;
	this->par = NULL;
	this->left = NULL;
	this->right = NULL;
}
	  void setLeft(Node* node) {
		  if (node == NULL) {
			  this->left = NULL;
		  }
		  else {
			  this->left = node;
			  node->par = this; //이해가 좀 안가넴 ..흠 
		  }
	  }
	  void setRight(Node* node) {
		  if (node == NULL) {
			  this->right = NULL;
		  }
		  else {
			  this->right = node;
			  node->par = this;
		  }
	  }

	  friend class BST;
};

class BST {
public:
	Node* root;
	BST() {
		this->root = NULL;
	}
	Node* search(int data) { //탐색연산 (찾으려는 노드가 있으면 그 노드를 리턴)
		Node* curN = this->root; 
		while (curN != NULL) {
			if (curN->data == data) {
				return curN;
			}
			else if (data > curN->data) curN = curN->right;
			else curN = curN->left;
		}
		return NULL;
	}
	void insert(int data) { //삽입연산
		Node* node = new Node(data); //삽입할 노드
		if (this->root == NULL) { //빈 트리일 경우
			this->root = node; //루트에 삽입하고
			return; //함수종료
		}

		//삽입해야할 위치찾기
		Node* parN = NULL;
		Node* curN = this->root;

		while (curN != NULL) {
			if (curN->data < data) {
				parN = curN;
				curN = curN->right;
			}
			else {
				parN = curN;
				curN = curN->left;
			}
		}
		//찾은 위치에 삽입
		if (data > parN->data) parN->setRight(node);
		else if (data < parN->data) parN->setLeft(node);
	}
	
	void remove(int data) {  //삭제연산 
		Node* node = this->search(data); //삭제할 노드찾기
		Node* parN = node->par; //삭제할 노드의 부모노드도 찾기

		if (node->left == NULL && node->right == NULL) { //삭제할 노드의 자식이 null=삭제할 노드가 외부노드인 경우
			if (parN->left == node) {
				parN->left = NULL;
			}
			else {
				parN->right = NULL;
			}
			delete node;

		}
		else if (node->left == NULL && node->right != NULL)  {//삭제할 노드가 오른쪽자식만 있을 경우
			if (parN->left == node) {
				parN->left = node->right;
				node->right->par = parN;
			}
			else {
				parN->right = node->right;
				node->right->par = parN;
			}
			delete node;

		}
		else if (node->left != NULL && node->right == NULL) { //삭제할 노드가 왼쪽 자식만 있을 경우
			if (parN->left == node) {
				parN->left = node->left;
				node->left->par = parN;
			}
			else {
				parN->right = node->left;
				node->left->par = parN;
			}
			delete node;

		}
		else { //삭제할 노드가 내부노드일 경우 

			Node* temp = node->right;
			
			while (temp->left != NULL) {
				temp = temp->left;
			}
			int x = node->data;
			node->data = temp->data;
			temp->data = x;
			if (temp->right != NULL) {
				temp->par->left = temp->right;
			}
				temp = NULL;
			}

		}
	int depth(int data) {
		Node* node = this->search(data); 
		int dep = 0; 
		while (node != root) {
			node = node->par;
			dep++;
		}
		return dep;
	}

};

int main() {
	int T;
	cin >> T;
	string oper; int x;
	BST tree;
	for (int i = 0; i < T; i++) {
		cin >> oper;
		if (oper == "insert") {
			cin >> x;
			tree.insert(x);
		}
		else if (oper == "delete") {
			cin >> x;
			tree.remove(x);
		}
		else if (oper == "depth") {
			cin >> x;
			cout << tree.depth(x) << endl;
		}
		else {
			cout << "다시" << endl;
		}
	}
}