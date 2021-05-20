//�ڷᱸ�� 11���� �ǽ� 4��
//BST+depth  remove()����� �̤�
//correct! 
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

		//������ ��尡 ��Ʈ��!!!! 
		if (node == root) {
			if (root->right == NULL) {
				root = root->left;
			}
			else {
				root = root->right;
			}
			delete node;
			return;
		}

		//������ ����� �ڽ��� ��� null�� ���
		if (node->left == NULL && node->right == NULL) { 
			if (parN->left == node) {
				parN->left = NULL;
			}
			else {
				parN->right = NULL;
			}
			delete node;
		}
		//������ ��尡 �������ڽĸ� ���� ���
		else if (node->left == NULL && node->right != NULL) {
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
		//������ ��尡 ���� �ڽĸ� ���� ���
		else if (node->left != NULL && node->right == NULL) { 
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
		else { //������ ����� �� �ڽ��� ��� ���γ���� ��� 

			Node* temp = node->right;

			while (temp->left != NULL) {
				temp = temp->left;
			} //temp=������

			int x = node->data;
			node->data = temp->data; //���� ������ ��忡 �������� ������
			temp->data = x; //�������� ������ �� ������, ���� �� �������� �����ϴ� ��!

			//�������� ������ ������ NULL�̹Ƿ� �����ʸ� Ȯ���ϸ� ��. 
			if (temp->right != NULL) {
				if (temp->par == node) //�������� �θ� ������ ����� ���
				{
					node->right = temp->right;
					temp->right->par = node;
				}
				else
				{
					temp->par->left = temp->right;
					temp->right->par = temp->par;
				}
			}
			else { //������ �ڽ��� ������ �������ڸ� null�� �ٲ��ֱ�. 
				if (temp->par == node) {
					node->right = NULL;
				}
				else {
					temp->par->left = NULL;
				}
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
			cout << "�ٽ�" << endl;
		}
	}
}