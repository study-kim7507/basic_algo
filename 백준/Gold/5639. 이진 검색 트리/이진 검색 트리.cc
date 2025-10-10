// BOJ 5639. 이진 검색 트리
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

typedef struct Node
{
	Node* leftChild;
	Node* rightChild;
	int key;
} Node;

void makeTree(Node*& parentNode, Node* newNode)
{
	if (parentNode == nullptr)
	{
		parentNode = newNode;
		return;
	}

	if (parentNode->key > newNode->key) makeTree(parentNode->leftChild, newNode);
	else makeTree(parentNode->rightChild, newNode);
}

void printTree(Node* parentNode)
{
	if (parentNode->leftChild != nullptr) printTree(parentNode->leftChild);
	if (parentNode->rightChild != nullptr) printTree(parentNode->rightChild);

	std::cout << parentNode->key << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Node* rootNode = nullptr;

	while (true)
	{
		string key_string;
		getline(cin, key_string);
		if (key_string.empty()) break;

		int key = stoi(key_string);
		
		Node* newNode = new Node();
		newNode->leftChild = nullptr; 
		newNode->rightChild = nullptr;
		newNode->key = key;

		makeTree(rootNode, newNode);
	}

	printTree(rootNode);

	return 0;
}