#include<iostream>
#include<vector>
using namespace std;

class Node {
public: 
	int data;
	Node* par;
	vector<Node*> chi_v;
	Node(int data) {
		this->data = data;
		this->par = NULL;
	}
};
class Tree {
public: 
	Node* root;
	vector<Node*> node_v; 

	Tree() {
		Node* node = new Node(1);
		root = node;
		node_v.push_back(node);
	}
	void insertNode(int pardata, int data) {
		for (int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == pardata) {
				Node* node = new Node(data); 
				node_v[i]->chi_v.push_back(node);
				node->par = node_v[i];
				node_v.push_back(node);
				return; //�߿�!!!!!!!!!1 
			}
		}
	}
	void postorderPar(Node* node) {
		if (!node)return;
		for (int i = 0; i < node->chi_v.size(); i++) {
			postorderPar(node->chi_v[i]);
		}
		if (node == root)
			cout << 0 << endl;
		else
			cout << node->par->data << " ";
	}
};
int main() {
	int Testcase;
	cin >> Testcase; //�׽�Ʈ ���̽� �Է¹ޱ�
	for (int i = 0; i < Testcase; i++) { //���̽����̽���ŭ �ݺ�
		Tree tree;
		int N;
		cin >> N; 
		for (int j = 0; j < N; j++) {
			int pardata, chidata;
			cin >> pardata >> chidata;
			tree.insertNode(pardata, chidata);
		}

		tree.postorderPar(tree.root);

	}
}