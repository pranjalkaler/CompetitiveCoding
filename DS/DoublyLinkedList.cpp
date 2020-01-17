#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
	Node(int d) : data(d), next(nullptr), prev(nullptr) { }
	~Node() {
		next = nullptr;
		prev = nullptr;
	}
	friend std::ostream& operator << (std::ostream& os, Node* node);
};

std::ostream& operator << (std::ostream& os, Node* node) {
	os << node->data;
	return os;
}

class DoublyLinkedList {
	Node *head;
	Node* rear;
public:
	DoublyLinkedList(Node* h = nullptr, Node* r = nullptr) : head(h), rear(r) {}
	void addNode(int data);
	bool deleteNode(int data);
	bool searchNode(int data);
	void insertNode(int data, int afterThis);
	friend std::ostream& operator << (std::ostream& os, DoublyLinkedList* list);
};

void DoublyLinkedList :: addNode(int data) {
	if(head == nullptr) {
		head = rear = new Node(data);
		return;
	}
	
	if(rear != nullptr) {
		auto newNode = new Node(data);
		rear->next = newNode;
		newNode->prev = rear;
		rear = newNode;
	}
}

bool DoublyLinkedList :: deleteNode(int data) {
	if(head == nullptr)
		return false;
	if(head->data == data) {
		auto tempNode = head;
		head = head->next;
		head->prev = nullptr;
		delete tempNode;
		return true;
	}

	auto trailNode = head;
	auto tempNode = trailNode->next;

	while(tempNode != nullptr) {
		if(tempNode->data == data) {
			trailNode->next = tempNode->next;
			if(tempNode->next != nullptr)
				tempNode->next->prev = trailNode;
			delete tempNode;
			return true;
		}
		trailNode = tempNode;
		tempNode = trailNode->next;
	}
	return false;
}

void DoublyLinkedList :: insertNode(int data, int afterThis) {
	if(head == nullptr) {
		head = rear = new Node(data);
		return;
	}

	if(afterThis == -999) {
		auto newNode = new Node(data);
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		return;
	}

	auto leadNode = head->next;
	auto trailNode = head;
	while(leadNode != nullptr) {
		if(trailNode->data == afterThis) {
			auto newNode = new Node(data);
			trailNode->next = newNode;
			newNode->prev = trailNode;
			newNode->next = leadNode;
			leadNode->prev = newNode;
			return;
		}
		trailNode = leadNode;
		leadNode = leadNode->next;
	}
	if(trailNode != nullptr) {
		// adding in the last
		auto newNode = new Node(data);
		trailNode->next = newNode;
		newNode->prev = trailNode;
		rear = newNode;
	}
}

bool DoublyLinkedList :: searchNode(int data) {
	if(head == nullptr)
		return false;
	auto tempNode = head;
	while(tempNode != nullptr) {
		if(tempNode->data == data)
			return true;
		tempNode = tempNode->next;
	}
	return false;
}

std::ostream& operator << (std::ostream& os, DoublyLinkedList* list) {
	if (list->head == nullptr) {
		os << "[HEAD = TAIL]" << endl;
		return os;
	}
	auto tempNode = list->head;
	os << "[HEAD]<->";
	while(tempNode != nullptr) {
		os << tempNode << "<->";
		tempNode = tempNode->next;
	}
	os << "[TAIL]" << endl;
	return os;
}

int main() {
	
	DoublyLinkedList *list = new DoublyLinkedList;
	cout << list;
	list->addNode(1);
	list->addNode(2);
	list->addNode(3);
	list->addNode(4);
	list->addNode(5);
	list->addNode(6);
	list->addNode(7);
	list->addNode(8);
	cout << list;

	if (list->searchNode(3)) {
		cout << "3 is in List" << endl;
	}

	if(!list->searchNode(5)) {
		cout << "5 is not in list" << endl;
	}

	if(list->deleteNode(1)) {
		cout << "1 deleted" << endl;
	}
	cout << list;
	
	if(list->deleteNode(4)) {
		cout << "4 deleted" << endl;
	}

	cout << list;
	
	if(list->deleteNode(8)) {
		cout << "8 deleted" << endl;
	}

	cout << list;

	if(!list->deleteNode(10)) {
		cout << "Unable to delete 10!" << endl;
	}
	list->deleteNode(4);

	cout << list;
	list->deleteNode(8);

	cout << list;

	list->insertNode(4, 3);
	list->insertNode(8, 7);
	list->insertNode(11, 10);
	list->insertNode(1, -999);

	cout << list;

	return 0;
}
