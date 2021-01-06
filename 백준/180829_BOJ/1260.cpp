#include <iostream>
#include <queue>
using namespace std;

int N, M, start, A, B;
int map[1001][1001] = { 0 };
bool check[2][10001] = { false };


void dfs(int start)
{
	printf("%d ", start);
	//이미 탐색했으면 종료
	if (check[0][start] == true) return;

	//탐색했으면 표시
	check[0][start] = true;

	for (int i = 1; i <= N; i++)
	{
		//연결되어있고 탐색안되었으면 계속 진행
		if (map[start][i] == 1 && !check[0][i])
			dfs(i);
	}


}

void bfs(int start)
{
	queue<int> q;
	//초기값
	q.push(start);
	//탐색했으면 표시
	check[1][start] = true;

	while (!q.empty())
	{
		//처음요소 저장하고 꺼냄
		int x = q.front();
		q.pop();

		printf("%d ", x);

		for (int i = 1; i <= N; i++)
		{
			//연결되어있고 탐색이 안되어있으면 큐에 넣는다.
			if (map[x][i] == 1 && !check[1][i])
			{
				check[1][i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &start);

	//그래프 구성
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &A, &B);
		map[A][B] = 1;
		map[B][A] = 1;
	}

	dfs(start);
	printf("\n");
	bfs(start);

	return 0;
}