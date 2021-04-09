#include <iostream>
#include <vector>
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
	vector<Node*> node_v; //��� ��带 ������ ����

	Tree(int data) { //Ʈ��  
		Node* node = new Node(data);
		this->root = node;
		this->node_v.push_back(node);
	}
	void insertNode(int par_data, int data) {
		Node* node = new Node(data);
		for (int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == par_data) {
				node_v[i]->chi_v.push_back(node);
				node_v.push_back(node);
				node->par = node_v[i];
				return;
			}
		}
		cout << -1 << endl; // �ش� �θ��尡 ������ -1���
	}

	void delNode(int data) {
		Node* curNode;
		Node* parNode;
		for (int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == data) {
				if (node_v[i] == root) {
					cout << -1 << endl;
					return;
				}
				curNode = node_v[i];
				parNode = curNode->par;
				for (Node* child : curNode->chi_v) {
					parNode->chi_v.push_back(child);
					child->par = parNode;
				}

				for (int j = 0; j < parNode->chi_v.size(); j++) {
					if (parNode->chi_v[j]->data == data) {
						parNode->chi_v.erase(parNode->chi_v.begin() + j);
					}
				}

				node_v.erase(node_v.begin() + i);
				delete curNode;
				return;
			}
		}
		cout << -1 << endl;
	}

	void printChi(int data) {
		for (int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == data) {
				if (node_v[i]->chi_v.empty()) {
					cout << -1 << endl;
					return;
				}
				for (Node* child : node_v[i]->chi_v) {
					cout << child->data << " ";
				}
				cout << endl;
				return;
			}
		}
		cout << -1 << endl;
	}

	void printPar(int data) {
		for (int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == data) {
				if (node_v[i] == root) {
					cout << -1 << endl;
					return;
				}
				cout << node_v[i]->par->data << endl;
				return;
			}
		}
		cout << -1 << endl;
	}
	void printLevel(int data) {
		for (int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == data) {
				/*if (node_v[i] == root) {
					cout << 1 << endl;
					return;
				}*/
				Node* curNode = node_v[i];
				int lev = 1;
				while (curNode!= root) {
					curNode = curNode->par;
					lev++;
				}
				cout << lev << endl;
				return;
			}
		}
		cout << -1 << endl;
	}
};

int main() {
	int n, t;
	Tree tree(1);
	cin >> n >> t;
	int p, d;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		tree.insertNode(p, d);
	}
	for (int i = 0; i < t; i++) {
		cin >> d;
		tree.printLevel(d);
	}
}