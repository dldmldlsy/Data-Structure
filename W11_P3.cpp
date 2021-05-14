////자료구조실습 11주차 3번 
////이진탐색트리 생성 후 오름차순으로 값출력
////correct!
// 
//#include<iostream>
//using namespace std;
//class Node {
//private:
//	int data;
//	Node* par;
//	Node* left;
//	Node* right;
//
//public: Node(int data) {
//	this->data = data;
//	this->par = NULL;
//	this->left = NULL;
//	this->right = NULL;
//}
//	  void setLeft(Node* node) {
//		  if (node == NULL) {
//			  this->left = NULL;
//		  }
//		  else {
//			  this->left = node;
//			  node->par = this; //이해가 좀 안가넴 ..흠 
//		  }
//	  }
//	  void setRight(Node* node) {
//		  if (node == NULL) {
//			  this->right = NULL;
//		  }
//		  else {
//			  this->right = node;
//			  node->par = this;
//		  }
//	  }
//
//	  friend class BST;
//};
//
//class BST {
//public:
//	Node* root;
//	BST() {
//		this->root = NULL;
//	}
//	Node* search(int data) { //탐색연산 (찾으려는 노드가 있으면 그 노드를 리턴)
//		Node* curN = this->root;
//		while (curN != NULL) {
//			if (curN->data == data) {
//				return curN;
//			}
//			else if (data > curN->data) curN = curN->right;
//			else curN = curN->left;
//		}
//		return NULL;
//	}
//	void insert(int data) { //삽입연산
//		Node* node = new Node(data); //삽입할 노드
//		if (this->root == NULL) { //빈 트리일 경우
//			this->root = node; //루트에 삽입하고
//			return; //함수종료
//		}
//
//		//삽입해야할 위치찾기
//		Node* parN = NULL;
//		Node* curN = this->root;
//
//		while (curN != NULL) {
//			if (curN->data < data) {
//				parN = curN;
//				curN = curN->right;
//			}
//			else {
//				parN = curN;
//				curN = curN->left;
//			}
//		}
//		//찾은 위치에 삽입
//		if (data > parN->data) parN->setRight(node);
//		else if (data < parN->data) parN->setLeft(node);
//	}
//
//	void inorder(Node* node) {
//		if (node==NULL) return; //이거 빼먹지말기!
//		inorder(node->left);
//		cout << node->data << " ";
//			inorder(node->right);
//	}
//};
//int main() {
//	int T;
//	cin >> T;
//	int N;
//	for (int i = 0; i < T; i++) {
//		BST tree;
//		cin >> N;
//		int x;
//		for (int j = 0; j < N; j++) {
//			cin >> x;
//			tree.insert(x);
//		}
//		tree.inorder(tree.root);
//	}
//}