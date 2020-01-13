#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int d) : data(d), left(nullptr), right(nullptr) { }
	~Node() {
		left = right = nullptr;
	}
};

class BST {
	Node* root;
public:
	BST(Node* r = nullptr) : root(r) { }
	void insertNode(Node* r, int data);
	bool search(Node* r, int data);
	void deleteNode(Node* r, int data);
	Node* getRoot() {
		return root;
	}
};

void BST :: insertNode(Node* r, int data) {
	if(root == nullptr) {
		root = new Node(data);
		return;
	}
	
	if(r->data <= data) {
		if(r->left != nullptr)
			insertNode(r->left, data);
		else {
			r->left = new Node(data);
			return;
		}
	}
	else {
		if(r->right != nullptr)
			insertNode(r->right, data);
		else {
			r->right = new Node(data);
			return;
		}
	}
}

bool BST :: search(Node* r, int data) {
	if(root == nullptr || r == nullptr)
		return false;
	if(r->data == data)
		return true;
	else {
		if(r->data <= data)
			return search(r->left, data);
		else
			return search(r->right, data);
	}
}

void BST :: deleteNode(Node* r, int data) {
	if(root == nullptr || r == nullptr) {
		return;
	}
}

const int COUNT = 10;
void print2DUtil(Node *root, int space)  
{
	if (root == nullptr)
		return;
	space += COUNT;
	print2DUtil(root->left, space);
	cout<<endl;
	for (int i = COUNT; i < space; i++)
		cout<<" ";
	cout<<root->data<<endl;
	print2DUtil(root->right, space);  
}

int main() {
	BST* bst = new BST;
	bst->insertNode(bst->getRoot(),10);
	bst->insertNode(bst->getRoot(),7);
	bst->insertNode(bst->getRoot(),8);
	bst->insertNode(bst->getRoot(),5);
	bst->insertNode(bst->getRoot(),1);
	bst->insertNode(bst->getRoot(),18);
	bst->insertNode(bst->getRoot(),3);
	bst->insertNode(bst->getRoot(),28);
	bst->insertNode(bst->getRoot(),9);
	
	print2DUtil(bst->getRoot(), 10);
	
	cout << bst->search(bst->getRoot(), 9);
	cout << bst->search(bst->getRoot(), 28);
	cout << bst->search(bst->getRoot(), 3);
	cout << bst->search(bst->getRoot(), 21);
	cout << endl;
	
	return 0;
}
