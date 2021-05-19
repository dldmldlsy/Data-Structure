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

	void remove(int data) {  //�������� 
		Node* node = this->search(data); //������ ���ã��
		Node* parN = node->par; //������ ����� �θ��嵵 ã��

		if (node->left == NULL && node->right == NULL) { //������ ����� �ڽ��� null=������ ��尡 �ܺγ���� ���
			if (parN->left == node) {
				parN->left = NULL;
			}
			else {
				parN->right = NULL;
			}
			delete node;

		}
		else if (node->left == NULL && node->right != NULL) {//������ ��尡 �������ڽĸ� ���� ���
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
		else if (node->left != NULL && node->right == NULL) { //������ ��尡 ���� �ڽĸ� ���� ���
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
		else { //������ ��尡 ���γ���� ��� 

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
	int sub(int data) {
		Node* node = this->search(data);
		if (node == NULL) {
			return 0;
		}
		int count = 0;
		if (node->left != NULL) {
			count += sub(node->left->data);
		}
		count++;
		if (node->right != NULL) {
			count += sub(node->right->data);
		}
		return count;
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
		else if (oper == "sub") {
			cin >> x;
			cout << tree.sub(x) << endl;
		}
		else {
			cout << "�ٽ�" << endl;
		}
	}
}
