  
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
	int key;
	Node *left, *right;

	Node(int key)
	{
		this->key = key;
		this->left = this->right = nullptr;
	}
};

void preorder(Node *root, int level, unordered_map<int, vector<int>>& map)
{
	
	if (root == nullptr)
		return;

	
	map[level].push_back(root->key);

	preorder(root->left, level + 1, map);
	preorder(root->right, level + 1, map);
}

void levelOrderTraversal(Node *root)
{

	unordered_map<int, vector<int>> map;

	
	preorder(root, 1, map);

	for (int i = 1; map[i].size() > 0; i++)
	{
		cout << "Level " << i << ": ";
		for (int i: map[i])
			cout << i << " ";

		cout << endl;
	}
}

int main()
{
	Node* root = nullptr;

    
	root = new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	root->left->left = new Node(8);
	root->left->right = new Node(12);
	root->right->left = new Node(16);
	root->right->right = new Node(25);
	root->right->right->right = new Node(30);

	levelOrderTraversal(root);

	return 0;
}