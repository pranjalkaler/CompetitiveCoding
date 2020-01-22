#include <iostream>
#include <bits/stdc++.h>

struct Node {

	std::string nodeValue;
	std :: map <std::string,Node*> nodeMap;
	bool isLastNode;
	
	Node(std::string letter = "NULL", bool iLN = false) : nodeValue(letter), isLastNode(iLN) { }
	~Node() {}

	void setLastNode(bool LN) {
		isLastNode = LN;
	}
	friend std::ostream& operator << (std::ostream& os, Node* node);
};

std::ostream& operator << (std::ostream& os, Node* node) {
	for (auto it = node->nodeMap.begin(); it != node->nodeMap.end(); ++it) {
		os << it->first << "-->" << it->second << "\n";
	}
	os << std :: endl;
}

class Trie {

	Node* Start;

public:
	Trie(Node* s = nullptr) : Start(s) {}
	void insert(std :: string word, Node* curr = nullptr);
};

void Trie :: insert(std :: string word, Node* curr) {
	if(curr == nullptr) {
		if(Start == nullptr) {
			Start = new Node;
			if(word.length() == 1) {
				Start->nodeMap.insert({word, new Node(word,true)});
				return;
			}
			else {
				std :: string letter(1, word[0]);
				Start->nodeMap.insert( {letter, new Node(letter)} );
				insert(word.substr(1, word.length() -1), Start->nodeMap.find(letter)->second);
			}
		}
	}
}

int main() {
	Trie *T = new Trie;
	T->insert("A");
	/*T->insert("");
	  if(T->find("")) {
	  std :: cout << "___ found in Trie" << std :: endl;
	  }*/
	return 0;
}	
