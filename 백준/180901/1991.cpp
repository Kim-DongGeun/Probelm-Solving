#include <iostream>
using namespace std;

int map[27][2];

int N;

void preorder(int cur)
{
	if (cur == '.' - 64) return;

	printf("%c", cur + 64);

	preorder(map[cur][0]);
	preorder(map[cur][1]);
}

void inorder(int cur)
{
	if (cur == '.' - 64) return;

	inorder(map[cur][0]);
	printf("%c", cur + 64);
	inorder(map[cur][1]);
}

void postorder(int cur)
{
	if (cur == '.' - 64) return;

	postorder(map[cur][0]);
	postorder(map[cur][1]);
	printf("%c", cur + 64);
}

int main()
{
	
	char a, b, c;
	scanf("%d", &N);

	//¸Ê
	for (int i = 1; i <= N; i++)
	{
		scanf(" %c %c %c", &a, &b, &c);
		map[a - 64][0] = b - 64;
		map[a - 64][1] = c - 64;
	}



	preorder(1);
	printf("\n");
	inorder(1);
	printf("\n");
	postorder(1);

	return 0;
}