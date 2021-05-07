#include<iostream>
#include<vector>
using namespace std;

class Node {
public: //
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
				return; //중요!!!!!!!!!1 
			}
		}
	}
	void preorder(Node* node) { //전위순회함수 (해당 노드에 대한 전위 순회가 이뤄져야하므로 노드가 인수)

		if (!node)return; //노드가 없을 시 바로 함수 종료
		if (node == root) 
			cout << 0 << endl;
		else 
			cout << node->par->data<< " ";
		for (int i = 0; i < node->chi_v.size(); i++) {
			preorder(node->chi_v[i]);
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
	cin >> Testcase; //테스트 케이스 입력받기
	for (int i = 0; i < Testcase; i++) { //테이스케이스만큼 반복
		Tree tree;
		int N;
		cin >> N;
		for (int j = 0; j < N; j++) {
			int pardata, chidata;
			cin >> pardata >> chidata;
			tree.insertNode(pardata, chidata);
		}

		tree.preorder(tree.root);

	}
}