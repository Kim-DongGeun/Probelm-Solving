/*
	idea : 이진트리를 만들어서 결과를 set에 저장
*/
#include <iostream>
#include <set>
#include <string>
using namespace std;

struct Node{
	int value;
	Node* left;
	Node* right;
	Node() {
		value = 0;
		left = NULL;
		right = NULL;
	}
};

int n, k;
int arr[20];
set<string> s;

string preorder(Node* root)
{
	string temp = "";
	temp += "V"; //방문
	if (root->left) {
		temp += "L";
		temp += preorder(root->left); //left
		temp += "l";
	}
	if (root->right) {
		temp += "R";
		temp += preorder(root->right); //right
		temp += "r";
	}
	temp += "v";
	return temp;
}

void remove(Node* root)
{
	if (root->left) remove(root->left);
	if (root->right) remove(root->right);

	delete root;
	
}

int main()
{
	scanf("%d %d", &n, &k);

	while (n--)
	{
		for (int i = 0; i < k; i++) {
			scanf("%d", &arr[i]);
		}

		Node* root = new Node;

		root->value = arr[0];

		for (int i = 1; i < k; i++)
		{
			Node* cur = root;
			while (true)
			{
				if (cur->value < arr[i]) //right
				{
					if (cur->right == NULL) {
						Node *New = new Node;
						cur->right = New;
						cur->right->value = arr[i];
						break;
					}
					else cur = cur->right;
				}
				else if (cur->value > arr[i]) //left
				{
					if (cur->left == NULL) {
						Node *New = new Node;
						cur->left = New;
						cur->left->value = arr[i];
						break;
					}
					else cur = cur->left;
				}
				else break;
			}
		}

		s.insert(preorder(root));
		remove(root);
	}
	printf("%d\n", s.size());
	return 0;
}