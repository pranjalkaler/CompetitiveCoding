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

class Stack {
	Node* top;
public:
	Stack(Node* t = nullptr) : top(t) {}
	void pushNode(int data);
	void popNode();
	Node* peek();
	bool isEmpty();
	friend std::ostream& operator << (std::ostream& os, Stack* stack);
};

void Stack :: pushNode(int data) {
	if(top == nullptr) {
		top = new Node(data);
		return;
	}
	auto newNode = new Node(data);
	newNode->next = top;
	top = newNode;
}

void Stack :: popNode() {
	if(top != nullptr) {
		auto tempNode = top;
		top = top->next;
		tempNode->next = nullptr;
		delete tempNode;
	}
}

Node* Stack :: peek() {
	return top;
}

bool Stack :: isEmpty() {
	if (top == nullptr)
		return true;
	return false;
}

std::ostream& operator << (std::ostream& os, Stack* stack) {
	if (stack->top == nullptr) {
		os << "[TOP = NULL]" << endl;
		return os;
	}
	auto tempNode = stack->top;
	os << "[TOP]->";
	while(tempNode != nullptr) {
		os << tempNode << "->";
		tempNode = tempNode->next;
	}
	os << "[NULL]" << endl;
	return os;
}

int main() {
	Stack* S = new Stack;
	if(S->isEmpty()) {
		cout << "Stack is empty" << endl << S;
	}
	S->pushNode(1);
	S->pushNode(2);
	S->pushNode(3);
	cout << S;
	S->popNode();
	cout << S;
	cout << "Peek Node: " << S->peek() << endl;

	return 0;
}
