//�ڷᱸ���ǽ� 11���� 1�� 
//����Ž��Ʈ�� ���� �� m��° ���� �����
 
#include<iostream>
#include<vector>
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
			  node->par = this; //���ذ� �� �Ȱ��� ..�� 
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
	vector<int> v;
	BST() {
		this->root = NULL;
	}
	Node* search(int data) { //Ž������ (ã������ ��尡 ������ �� ��带 ����)
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
	void insert(int data) { //���Կ���
		Node* node = new Node(data); //������ ���
		if (this->root == NULL) { //�� Ʈ���� ���
			this->root = node; //��Ʈ�� �����ϰ�
			return; //�Լ�����
		}

		//�����ؾ��� ��ġã��
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
		//ã�� ��ġ�� ����
		if (data > parN->data) parN->setRight(node);
		else if (data < parN->data) parN->setLeft(node);
	}

	void inorder(Node* node) {
		if (node==NULL) return; //�̰� ����������!
		inorder(node->left);
		v.push_back(node->data);
		inorder(node->right);
	}
	int printM(int m) {
		int res = v[m - 1];
		return res;
	}
};
int main() {
	int T;
	cin >> T;
	int N, M;
	for (int i = 0; i < T; i++) {
		BST tree;
		cin >> N;
		int x;
		for (int j = 0; j < N; j++) {
			cin >> x;
			tree.insert(x);
		}
		cin >> M;
		tree.inorder(tree.root);
		cout<<tree.printM(M) << endl;
	}
}