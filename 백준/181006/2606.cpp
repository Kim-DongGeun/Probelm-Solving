/*
	idea : 유니온 파인드로 찾기
*/
#include <iostream>
using namespace std;

int parent[101];

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
	int n, m, a, b;
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	while (m--)
	{
		scanf("%d %d", &a, &b);
		Union(a, b);
	}

	int ans = 0;
	for (int i = 2; i <= n; i++)
		if (find(1) == find(i)) ans++;

	printf("%d\n", ans);
	return 0;
}