//�ڷᱸ�� 13���� �ǽ� 1��
//isAdjacentTo() ����
//correct!
#include<iostream>
using namespace std;
struct vertex {
	int vertex_id; //���� ������ȣ
	int matrix_id; //������ edge matrix������ �ε���

	vertex* prev;
	vertex* next;

	vertex() { //����Ʈ ������ 
		vertex_id = matrix_id = -1;
		prev = next = NULL;
	}
	vertex(int vertex_id) { //������ȣ�� �Ű������� �޴� ������
		this->vertex_id = vertex_id;
		matrix_id = -1;
		prev = next = NULL;
	}
};

struct edge { //���� 
	vertex* src; //�����
	vertex* dst; //������
	edge* prev; //���������� ��
	edge* next; //��

	edge() { //����Ʈ ������
		src = dst = NULL;
		prev = next = NULL;
	}
	edge(vertex* src, vertex* dst) { //����� �� ������ �ο��޴� ������
		this->src = src;
		this->dst = dst;
		prev = next = NULL;
	}
};
class VertexList { //�������� �̷���� ���Ḯ��Ʈ 
	vertex* header;
	vertex* trailer;

public:
	VertexList() {
		header = new vertex();
		trailer = new vertex();
		header->next = trailer;
		trailer->prev = header;
	}
	void insert_back(vertex* new_vertex) { //�ڿ� �� �����߰� 

		//���� trailer�� ����- �߰��� ����-trailer ������ ����
		new_vertex->prev = trailer->prev;
		new_vertex->next = trailer;

		new_vertex->matrix_id = new_vertex->prev->matrix_id + 1;

		//�̰͵� ���� ����
		trailer->prev->next = new_vertex;
		trailer->prev = new_vertex;
		return;
	}

	void remove(vertex* del_vertex) {//��������Ʈ���� �������� 

		//�����ϴ� ���� �����ź��� ��Ĺ�ȣ �ϳ��� ���̱�
		for (vertex* cur = del_vertex->next; cur != trailer; cur = cur->next)
			cur->matrix_id--;
		//������ ���� �յ� ���� �̾��ֱ�
		del_vertex->prev->next = del_vertex->next;
		del_vertex->next->prev = del_vertex->prev;
		//��������
		delete del_vertex;
		return;
	}
	vertex* find_vertex(int vertex_id) { //���� Ž�� (������ ������ȣ) 
		//����Ʈ�� ������� ���������� next�� ���鼭 Ž��
		for (vertex* cur = header->next; cur != trailer; cur = cur->next)
			if (cur->vertex_id == vertex_id) return cur; //�߰��ϸ� ����
		return NULL;
	}
};

class EdgeList { //�������� �̷���� ���߿��Ḯ��Ʈ
	edge* header;
	edge* trailer;
public:
	EdgeList() { //����Ʈ ������
		//��� Ʈ���Ϸ� ����
		header = new edge();
		trailer = new edge();
		//�� �̾���.
		header->next = trailer;
		trailer->prev = header;
	}
	void insert_back(edge* new_edge) { //����Ʈ �ڿ� �� ���� �߰�
		//�������� �޾��ְ� ���ắ�����ֱ�
		new_edge->prev = trailer->prev;
		new_edge->next = trailer;
		trailer->prev->next = new_edge;
		trailer->prev = new_edge;
		return;
	}

	void remove(edge* del_edge) { //Ư������ ���� 
		//���ᱸ������
		del_edge->prev->next = del_edge->next;
		del_edge->next->prev = del_edge->prev;
		delete del_edge; //����
		return;
	}
};
class graph { //�׷��� Ŭ����!
	edge*** edge_matrix; //����Ÿ���� edge*�� �������迭= edge������ �����ϴ� matrix �������
	VertexList vertex_list; //��ü ������ �����ϴ� ���߿��Ḯ��Ʈ
	EdgeList edge_list; //��ü ������ �����ϴ� ���߿��Ḯ��Ʈ
	int vertex_size; //�׷����� �����ϴ� �������� (����� ������*������ �������̹Ƿ� �ʿ��� �ʵ�) 

public:
	graph() { //������ (���������� ������� �ʱ�ȭ
		vertex_size = 0;
		edge_matrix = NULL;
	}
	void insert_vertex(int vertex_id) { //�����߰�(������ȣ) 
		//�� ������ȣ�� ���� ������ �̹� ��������Ʈ�� �����ϴ��� Ȯ��
		if (vertex_list.find_vertex(vertex_id) != NULL) return;

		//���ٸ�
		//�� ������ȣ�� ���� �� ���� ����
		vertex* new_vertex = new vertex(vertex_id);

		//ũ�Ⱑ (������������+1)*(������������+1)�� �� ������� ����
		edge*** new_matrix = new edge * *[vertex_size + 1];
		for (int i = 0; i < vertex_size + 1; i++)
			new_matrix[i] = new edge * [vertex_size + 1]; //���࿡ �������������� edge*Ÿ���� �迭 �����Ҵ� 

		//������ �ִ� ���� ����
		for (int i = 0; i < vertex_size; i++)
			for (int j = 0; j < vertex_size; j++)
				new_matrix[i][j] = edge_matrix[i][j];
		//���Ӱ� �߰��� ����(���� 0~v, ���� v, ���� 0~v, ���� v�� �κ�)�� null
		for (int i = 0; i < vertex_size + 1; i++)
			new_matrix[i][vertex_size] = new_matrix[vertex_size][i] = NULL;

		//������� edge_matrix�� ������ ��������� 0,0�� �ּҸ� ������ ����.-> ���� ������� �Ҵ����� 
		for (int i = 0; i < vertex_size; i++)
			delete[] edge_matrix[i];
		delete[] edge_matrix;

		//���� ���� ��������� edge_matrix�� ����. 
		edge_matrix = new_matrix;
		//�� ������ ��������Ʈ�� �߰�
		vertex_list.insert_back(new_vertex);
		vertex_size++; //��������������. 
		return;
	}

	void erase_vertex(int vertex_id) { //�������� 
		//�� ������ȣ�� ���� ������ �ִ��� Ȯ��
		vertex* del_vertex = vertex_list.find_vertex(vertex_id);
		if (del_vertex == NULL)return; //���ٸ� �Լ�����. 

		int del_idx = del_vertex->matrix_id; //������ ������ ��Ĺ�ȣ

		edge*** new_matrix = new edge * *[vertex_size - 1]; //ũ�Ⱑ ������������-1�� �� edge matrix ���� 
		for (int i = 0; i < vertex_size - 1; i++)
			new_matrix[i] = new edge * [vertex_size + -1];

		//�� ��Ŀ� ������ ������ ���� �� ���� �������뺹�� 
		for (int i = 0; i < vertex_size - 1; i++) {
			for (int j = 0; j < vertex_size - 1; j++) {
				if (i < del_idx && j < del_idx) new_matrix[i][j] = edge_matrix[i][j];
				else if (i < del_idx) new_matrix[i][j] = edge_matrix[i][j + 1];
				else if (j < del_idx)new_matrix[i][j] = edge_matrix[i + 1][j];
				else new_matrix[i][j] = edge_matrix[i + 1][j + 1];
			}
		}
		for (int i = 0; i < vertex_size; i++)
			if (edge_matrix[del_idx][i] != NULL)
				edge_list.remove(edge_matrix[del_idx][i]);

		for (int i = 0; i < vertex_size; i++)
			delete[] edge_matrix[i];
		delete[] edge_matrix;


		edge_matrix = new_matrix;
		vertex_list.remove(del_vertex);
		vertex_size--;
		return;
	}

	void insertEdge(int src_vertex_id, int dst_vertex_id) {//���� ����. 
		vertex* src_vertex = vertex_list.find_vertex(src_vertex_id);
		vertex* dst_vertex = vertex_list.find_vertex(dst_vertex_id);
		if (src_vertex == NULL || dst_vertex == NULL) return;
		int src_id = src_vertex->matrix_id;
		int dst_id = dst_vertex->matrix_id;
		if (edge_matrix[src_id][dst_id] != NULL || edge_matrix[dst_id][src_id] != NULL) {
			cout << "Exist" << endl;
			return;
		}
		edge* new_edge = new edge(src_vertex, dst_vertex); //�� ���� ����.
		edge_list.insert_back(new_edge);
		edge_matrix[src_id][dst_id] = edge_matrix[dst_id][src_id] = new_edge;
		return;
	}

	void eraseEdge(int src_vertex_id, int dst_vertex_id) {
		vertex* src_vertex = vertex_list.find_vertex(src_vertex_id);
		vertex* dst_vertex = vertex_list.find_vertex(dst_vertex_id);

		if (src_vertex == NULL || dst_vertex == NULL) return;
		int src_id = src_vertex->matrix_id;
		int dst_id = dst_vertex->matrix_id;
		if (edge_matrix[src_id][dst_id] == NULL || edge_matrix[dst_id][src_id] == NULL) {
			cout << "None" << endl;
			return; //������ �������� ����
		}
		edge_list.remove(edge_matrix[src_id][dst_id]);
		edge_matrix[src_id][dst_id] = edge_matrix[dst_id][src_id] = NULL;
		return;
	}

	void incidentEdges(int vertex_id) {
		if (vertex_list.find_vertex(vertex_id) == NULL) return;
		vertex* _vertex = vertex_list.find_vertex(vertex_id);
		int count = 0;
		int m_num = _vertex->matrix_id;
		for (int i = 0; i < vertex_size; i++) {
			if (edge_matrix[m_num][i] != NULL) {
				count++;
			}
		}
		cout << count << endl;
	}
	void isAdjacentTo(int src_vertex_id, int dst_vertex_id) {
		vertex* src_vertex = vertex_list.find_vertex(src_vertex_id);
		vertex* dst_vertex = vertex_list.find_vertex(dst_vertex_id);
		if (src_vertex == NULL || dst_vertex == NULL) return;
		int src_id = src_vertex->matrix_id;
		int dst_id = dst_vertex->matrix_id;
		if (edge_matrix[src_id][dst_id] != NULL) {
			cout << "True" << endl;
			return;
		}
		cout << "False" << endl;
		return;
	}

};

int main() {
	int t, n;
	cin >> t >> n;
	graph g;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		g.insert_vertex(x);
	}
	string oper; int s, d;
	for (int i = 0; i < t; i++) {
		cin >> oper;
		if (oper == "insertEdge") {
			cin >> s >> d;
			g.insertEdge(s, d);
		}
		else if (oper == "eraseEdge") {
			cin >> s >> d;
			g.eraseEdge(s, d);
		}
		else if (oper == "incidentEdges") {
			cin >> s;
			g.incidentEdges(s);
		}
		else if (oper == "isAdjacentTo") {
			cin >> s >> d;
			g.isAdjacentTo(s, d);
		}
		else {
			cout << "�ٽ�" << endl;
		}
	}
}