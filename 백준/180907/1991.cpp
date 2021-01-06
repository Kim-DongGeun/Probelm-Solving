#include <iostream>
using namespace std;

int Arr[26][2];

void preorder(int root)
{
	if (root == '.' - 'A') return;
	printf("%c", (char)(root + 'A'));
	preorder(Arr[root][0]);
	preorder(Arr[root][1]);
}
void inorder(int root)
{
	if (root == '.' - 'A') return;
	inorder(Arr[root][0]);
	printf("%c", (char)(root + 'A'));
	inorder(Arr[root][1]);
}
void postorder(int root)
{
	if (root == '.' - 'A') return;
	postorder(Arr[root][0]);
	postorder(Arr[root][1]);
	printf("%c", (char)(root + 'A'));
}



void search(int root)
{
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
}



int main()
{
	int N;
	char a,b,c;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf(" %c %c %c", &a, &b, &c);
		Arr[a - 'A'][0] = b - 'A';
		Arr[a - 'A'][1] = c - 'A';
	}

	search(0);

	return 0;
}