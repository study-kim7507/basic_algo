// BOJ 5639. 이진 검색 트리
#include <iostream>
#include <vector>
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

// 왼쪽 -> 루트 -> 오른쪽
void inOrder(Node* curNode)
{
	if (curNode->leftChild != nullptr) inOrder(curNode->leftChild);
	if (curNode->rightChild != nullptr) inOrder(curNode->rightChild);
	std::cout << curNode->key << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Node* rootNode = nullptr;
	while (true)
	{
		string input;
		getline(cin, input);
		if (input.empty()) break;

		Node* newNode = new Node();
		newNode->leftChild = nullptr;
		newNode->rightChild = nullptr;
		newNode->key = stoi(input);

		makeTree(rootNode, newNode);
	}

	inOrder(rootNode);
	return 0;
}