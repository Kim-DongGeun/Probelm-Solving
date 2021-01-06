/*
	idea : 유니온 파인드 사용
*/
#include <iostream>
using namespace std;

int parent[1000001];
int find(int x)
{
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	parent[y] = x;
}

int main()
{
	int n, m;
	int a, b, c;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &c, &a, &b);
		if (c) //c == 1
		{
			int rootA = find(a);
			int rootB = find(b);
			if (rootA == rootB) printf("YES\n");
			else printf("NO\n");
		}
		else //c == 0
		{
			Union(a, b);
		}
	}
	return 0;
}