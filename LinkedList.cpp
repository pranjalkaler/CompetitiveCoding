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

class LinkedList {
	Node *head;
public:
	LinkedList(Node* h = nullptr) : head(h) {}
	void addNode(int data);
	bool deleteNode(int data);
	bool searchNode(int data);
	void insertNode(int data, int afterThis);
	friend std::ostream& operator << (std::ostream& os, LinkedList* list);
};

void LinkedList :: addNode(int data) {
	if(head == nullptr) {
		head = new Node(data);
		return;
	}
	auto tempNode = head;
	while(tempNode->next != nullptr) {
		tempNode = tempNode->next;
	}
	auto newNode = new Node(data);
	tempNode->next = newNode;
}

bool LinkedList :: deleteNode(int data) {
	if(head == nullptr)
		return false;
	if(head->data == data) {
		auto tempNode = head;
		head = head->next;
		delete tempNode;
		return true;
	}

	auto trailNode = head;
	auto tempNode = trailNode->next;

	while(tempNode != nullptr) {
		if(tempNode->data == data) {
			trailNode->next = tempNode->next;
			delete tempNode;
			return true;
		}
		trailNode = tempNode;
		tempNode = trailNode->next;
	}
	return false;
}

void LinkedList :: insertNode(int data, int afterThis) {
	if(head == nullptr) {
		head = new Node(data);
		return;
	}

	if(afterThis == -999) {
		auto newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		return;
	}

	auto leadNode = head->next;
	auto trailNode = head;
	while(leadNode != nullptr) {
		if(trailNode->data == afterThis) {
			auto newNode = new Node(data);
			trailNode->next = newNode;
			newNode->next = leadNode;
			return;
		}
		trailNode = leadNode;
		leadNode = leadNode->next;
	}
	if(trailNode != nullptr) {
		trailNode->next = new Node(data);
	}
}

bool LinkedList :: searchNode(int data) {
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

std::ostream& operator << (std::ostream& os, LinkedList* list) {
	if (list->head == nullptr) {
		os << "[HEAD = NULL]" << endl;
		return os;
	}
	auto tempNode = list->head;
	os << "[HEAD]->";
	while(tempNode != nullptr) {
		os << tempNode << "->";
		tempNode = tempNode->next;
	}
	os << "[NULL]" << endl;
	return os;
}

int main() {
	
	LinkedList *list = new LinkedList;
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
	
	if(list->deleteNode(4)) {
		cout << "4 deleted" << endl;
	}
	
	if(list->deleteNode(8)) {
		cout << "8 deleted" << endl;
	}

	if(!list->deleteNode(10)) {
		cout << "Unable to delete 10!" << endl;
	}
	list->deleteNode(4);
	list->deleteNode(8);

	cout << list;

	list->insertNode(4, 3);
	list->insertNode(8, 7);
	list->insertNode(11, 10);
	list->insertNode(1, -999);

	cout << list;

	return 0;
}
