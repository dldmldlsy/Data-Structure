//#include <iostream>
//#include <string>
//using namespace std;
//
//template<typename T>
//struct Node {
//public:
//	T data;
//	Node <T>* prev;
//	Node <T>* next;
//
//
//	Node() {
//		prev = next = NULL;
//
//	}
//	Node(T data) {
//		this->data = data;
//		prev = next = NULL;
//
//	}
//};
//
//template<typename T>
//class LinkedList {
//public:
//	Node<T>* header;
//	Node<T>* trailer;
//
//	LinkedList() {
//		header = new Node<T>();
//		trailer = new Node<T>();
//		header->next = trailer;
//		trailer->prev = header;
//	}
//	void insert_back(Node<T>* newNode) {
//		newNode->prev = trailer->prev;
//		newNode->next = trailer;
//		trailer->prev->next = newNode;
//		trailer->prev = newNode;
//		return;
//	}
//	void remove(Node<T>* delNode) {
//		delNode->prev->next = delNode->next;
//		delNode->next->prev = delNode->prev;
//		delete delNode;
//		return;
//	}
//};
//
//struct edge;
//
//struct vertex {
//	int vertex_id;
//	int degree;
//	bool visited;
//	LinkedList<edge*>* incident_edges; //정점과 인접한 간선 리스트
//	Node<vertex*>* vertex_node; //그래프의 정점리스트의 노드 포인터
//
//	vertex() {
//		vertex_id = degree = 0;
//		incident_edges = new LinkedList<edge*>();
//		vertex_node = new Node<vertex*>(this);
//		visited = false;
//	}
//	vertex(int vertex_id) {
//		this->vertex_id = vertex_id;
//		degree = 0;
//		incident_edges = new LinkedList<edge*>();
//		vertex_node = new Node<vertex*>(this);
//		visited = false;
//	}
//};
//
//struct edge {
//	vertex* src_vertex;
//	vertex* dst_vertex;
//	Node<edge*>* src_incident_edge_node; //시작 정점의 인접 간선리스트의 노드 포인터
//	Node<edge*>* dst_incident_edge_node; //끝 정접의 인접 간선리스트의 노드 포인터
//	Node<edge*>* total_edge_node; //그래프의 간선리스트의 노드 포인터
//
//	edge() {
//		src_vertex = NULL;
//		dst_vertex = NULL;
//		src_incident_edge_node = new Node<edge*>(this);
//		dst_incident_edge_node = new Node<edge*>(this);
//		total_edge_node = new Node<edge*>(this);
//	}
//	edge(vertex* src_vertex, vertex* dst_vertex) {
//		this->src_vertex = src_vertex;
//		this->dst_vertex = dst_vertex;
//		src_incident_edge_node = new Node<edge*>(this);
//		dst_incident_edge_node = new Node<edge*>(this);
//		total_edge_node = new Node<edge*>(this);
//	}
//};
//
//class graph {
//private:
//	LinkedList<vertex*>* vertex_list;
//	LinkedList<edge*>* edge_list;
//	int vertex_size;
//public:
//	graph() {
//		vertex_list = new LinkedList<vertex*>();
//		edge_list = new LinkedList<edge*>();
//		vertex_size = 0;
//	}
//	vertex* find_vertex(int vertex_id) {
//		for (Node<vertex*>* cur = vertex_list->header->next; cur != vertex_list->trailer; cur = cur->next) {
//			if (cur->data->vertex_id == vertex_id) return cur->data;
//		}
//		return NULL;
//	}
//	edge* find_edge(vertex* src, vertex* dst) {
//		if (src->degree <= dst->degree) {
//			for (Node<edge*>* cur = src->incident_edges->header->next; cur != src->incident_edges->trailer; cur = cur->next) {
//				if (cur->data->dst_vertex == dst) return cur->data;
//			}
//		}
//		else {
//			for (Node<edge*>* cur = dst->incident_edges->header->next; cur != dst->incident_edges->trailer; cur = cur->next) {
//				if (cur->data->src_vertex == src) return cur->data;
//			}
//		}
//		return NULL;
//	}
//	void insert_vertex(int vertex_id) {
//		if (find_vertex(vertex_id) != NULL) return;
//		vertex* new_vertex = new vertex(vertex_id);
//		vertex_list->insert_back(new_vertex->vertex_node);
//		vertex_size++;
//		return;
//	}
//	void insert_edge(int src_id, int dst_id) {
//		vertex* src = find_vertex(src_id);
//		vertex* dst = find_vertex(dst_id);
//
//		if (src == NULL || dst == NULL) return;
//		if (find_edge(src, dst) != NULL) return;
//
//		edge* new_edge = new edge(src, dst);
//		src->incident_edges->insert_back(new_edge->src_incident_edge_node); //각 리스트에 추가
//		dst->incident_edges->insert_back(new_edge->dst_incident_edge_node); //각 리스트에 추가
//		edge_list->insert_back(new_edge->total_edge_node);
//		src->degree++;
//		dst->degree++;
//		return;
//	}
//	void DFS(vertex* node) {
//		node->visited = true;
//		cout << node->vertex_id << " ";
//		for (Node<edge*>* n = node->incident_edges->header->next; n != node->incident_edges->trailer; n = n->next) {
//			edge* e = n->data;
//			if (e->src_vertex == node && e->dst_vertex->visited == false) {
//				DFS(e->dst_vertex);
//			}
//			else if (e->dst_vertex == node && e->src_vertex->visited == false) {
//				DFS(e->src_vertex);
//			}
//		}
//	}
//	void DFS(int start) {
//		vertex* start_vertex = find_vertex(start);
//		DFS(start_vertex);
//	}
//
//};
//int main() {
//	int c_count;
//	int verNum;
//	int edgeNum;
//	int vertex_a;
//	int vertex_b;
//
//	graph* grph = new graph();
//
//	cin >> c_count;
//	for (int i = 0; i < c_count; i++) { //테스트 시작
//		graph* grph = new graph();
//
//		//정점과 간선 생성
//		cin >> verNum >> edgeNum;
//		for (int j = 0; j < edgeNum; j++) {
//			cin >> vertex_a >> vertex_b;
//			grph->insert_vertex(vertex_a);
//			grph->insert_vertex(vertex_b);
//			grph->insert_edge(vertex_a, vertex_b);
//		}
//
//		grph->DFS(1);
//		cout << "\n";
//
//		delete grph;
//	}
//}