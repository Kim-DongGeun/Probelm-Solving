/*
	idea : bfs문제 상황 6가지를 다넣으면 됨
*/
#include <iostream>
#include <queue>
using namespace std;

bool ans[201];
bool check[201][201];

struct bottle 
{
	int a;
	int b;
	int c;
};

int main()
{
	int ma, mb, mc;
	
	scanf("%d %d %d", &ma, &mb, &mc);

	queue<bottle> q;
	q.push({ 0,0,mc });

	while (!q.empty())
	{
		bottle now = q.front();
		q.pop();

		if (check[now.a][now.b]) continue;
		check[now.a][now.b] = true;
		if (now.a == 0) ans[now.c] = true;


		if (now.a + now.b <= mb) q.push({ 0, now.a + now.b, now.c });
		else q.push({ now.a + now.b - mb, mb, now.c }); //A -> B

		if (now.a + now.c <= mc) q.push({ 0, now.b, now.a + now.c });
		else q.push({ now.a + now.c - mc, now.b, mc });// A -> C

		if (now.b + now.c <= mc) q.push({ now.a, 0, now.b + now.c });
		else q.push({ now.a, now.b + now.c - mc, mc });// B -> C

		if (now.a + now.b <= ma) q.push({ now.a + now.b, 0, now.c });
		else q.push({ ma, now.a + now.b - ma, now.c });// B -> A

		if (now.a + now.c <= ma) q.push({ now.a + now.c, now.b, 0 });
		else q.push({ ma, now.b, now.a + now.c - ma });// C -> A

		if (now.b + now.c <= mb) q.push({ now.a, now.b + now.c ,0 });
		else q.push({ now.a, mb, now.b + now.c - mb });// C -> B
	}
	for (int i = 0; i <= mc; i++)
		if (ans[i]) printf("%d ", i);
	return 0;
}