// Author: Pranjal Kaler

#include <bits/stdc++.h>

class TrieNode {

	using MAP = std :: map <std::string, std :: shared_ptr<TrieNode>>;

	std::string nodeValue;
	MAP nodeMap;
	bool _isLastNode;

public:
	std::string getNodeValue() {
		return this->nodeValue;
	}

	bool isLastNode() {
		return this->_isLastNode;
	}

	void setLastNode(bool val) {
		this->_isLastNode = val;
	}

	MAP& getNodeMap() {
		return this->nodeMap;
	}
	
	TrieNode(std::string letter = "NULL", bool iLN = false) : nodeValue(letter), _isLastNode(iLN) {}
	~TrieNode() {}

	void insert(std :: string str);
	bool find(std :: string str);
	void printAll(std :: shared_ptr<TrieNode> _node, std::string str = "");
};

void TrieNode :: insert (std :: string str) {
	auto _char = std :: string(1, str.at(0));
	bool _ILN = (str.size() == 1) ? true : false;

	auto mapItr = this->nodeMap.find(_char);
	if(mapItr == this->nodeMap.end()) {
		std :: shared_ptr<TrieNode> _node = std :: make_shared<TrieNode>(_char, _ILN);
		this->nodeMap[_char] = _node;
		if(_ILN)
			return;
		else {
			_node->insert(std :: string(str.begin()+1, str.end()));
		}
	}
	else {
		if(_ILN) {
			mapItr->second->setLastNode(true);
		}
		else {
			mapItr->second->insert(std :: string(str.begin()+1, str.end()));
		}
	}
}

bool TrieNode :: find (std :: string str) {
	if(str.size() == 0)
		return false;
	auto _char = std :: string(1, str.at(0));
	bool _ILN = (str.size() == 1) ? true : false;

	auto mapItr = this->nodeMap.find(_char);
	if(mapItr == this->nodeMap.end()) {
		return false;
	}
	else {
		if(_ILN && mapItr->second->isLastNode())
			return true;
		else 
			return mapItr->second->find(std :: string(str.begin()+1, str.end()));
	}
}

void TrieNode :: printAll (std :: shared_ptr<TrieNode> _node, std::string str) {
	if(_node == nullptr)
		return;
	if(_node->isLastNode()) {
		std :: cout << str << std :: endl;
	}

	for(auto itr : _node->nodeMap) {
		if(itr.second) {
			this->printAll(itr.second, str + itr.first);
		}
	}
}

int main() {
	std :: shared_ptr<TrieNode> Trie = std :: make_shared<TrieNode>();
	Trie->insert("A");
	Trie->insert("Alpha");
	Trie->insert("Birthday");
	Trie->insert("Alphabet");
	Trie->insert("The");
	Trie->insert("These");
	Trie->insert("Their");
	Trie->insert("Them");

	std :: cout << Trie->find("A") << std :: endl;
	std :: cout << Trie->find("B") << std :: endl;
	std :: cout << Trie->find("Alpha") << std :: endl;
	std :: cout << Trie->find("Beta") << std :: endl;
	std :: cout << Trie->find("Birthday") << std :: endl;
	std :: cout << Trie->find("These") << std :: endl;
	std :: cout << Trie->find("Alp") << std :: endl;
	std :: cout << Trie->find("Birth") << std :: endl;
	std :: cout << Trie->find("Them") << std :: endl;
	std :: cout << Trie->find("Alphabeta") << std :: endl;
	std :: cout << Trie->find("Them") << std :: endl;
	std :: cout << std :: endl;

	Trie->printAll(Trie);
	return 0;
}

/*

Expected output:

1
0
1
0
1
1
0
0
1
0
1

A
Alpha
Alphabet
Birthday
The
Their
Them
These

*/
