#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int d) : data(d), next(nullptr) { }
	~Node() {
		next = nullptr;
	}
	friend std::ostream& operator << (std::ostream& os, Node* node);
};

std::ostream& operator << (std::ostream& os, Node* node) {
	os << node->data;
	return os;
}

class Queue {
	Node* front;
	Node* rear;
public:
	Queue(Node* f = nullptr, Node* r = nullptr) : front(f), rear(r) {}
	void enqueue(int data);
	void dequeue();
	Node* frontNode();
	Node* rearNode();
	bool isEmpty();
	friend std::ostream& operator << (std::ostream& os, Queue* queue);
};

void Queue :: enqueue(int data) {
	if(front == nullptr) {
		front = rear = new Node(data);
		return;
	}
	rear->next = new Node(data);
	rear = rear->next;
}

void Queue :: dequeue() {
	if(front != nullptr) {
		auto tempNode = front;
		front = front->next;
		if(rear == tempNode)
			rear = nullptr;
		tempNode->next = nullptr;
		delete tempNode;
	}
}

Node* Queue :: frontNode() {
	return front;
}

Node* Queue :: rearNode() {
	return rear;
}

bool Queue :: isEmpty() {
	if (front == nullptr)
		return true;
	return false;
}

std::ostream& operator << (std::ostream& os, Queue* queue) {
	if (queue->front == nullptr) {
		os << "[FRONT = NULL = REAR]" << endl;
		return os;
	}
	auto tempNode = queue->front;
	os << "[FRONT]->";
	while(tempNode != nullptr) {
		os << tempNode << "->";
		tempNode = tempNode->next;
	}
	os << "[REAR|NULL]" << endl;
	return os;
}

int main() {
	Queue* Q = new Queue;
	if(Q->isEmpty()) {
		cout << "Queue is empty" << endl << Q;
	}
	Q->enqueue(1);
	Q->enqueue(2);
	Q->enqueue(3);
	cout << Q;
	Q->dequeue();
	cout << Q;
	cout << "Front Node: " << Q->frontNode() << endl;
	cout << "Rear Node: " << Q->rearNode() << endl;

	return 0;
}
