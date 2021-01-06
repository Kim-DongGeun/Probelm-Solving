#include <iostream>
#include <queue>
using namespace std;

int N, M, start, A, B;
int map[1001][1001] = { 0 };
bool check[2][10001] = { false };


void dfs(int start)
{
	printf("%d ", start);
	//�̹� Ž�������� ����
	if (check[0][start] == true) return;

	//Ž�������� ǥ��
	check[0][start] = true;

	for (int i = 1; i <= N; i++)
	{
		//����Ǿ��ְ� Ž���ȵǾ����� ��� ����
		if (map[start][i] == 1 && !check[0][i])
			dfs(i);
	}


}

void bfs(int start)
{
	queue<int> q;
	//�ʱⰪ
	q.push(start);
	//Ž�������� ǥ��
	check[1][start] = true;

	while (!q.empty())
	{
		//ó����� �����ϰ� ����
		int x = q.front();
		q.pop();

		printf("%d ", x);

		for (int i = 1; i <= N; i++)
		{
			//����Ǿ��ְ� Ž���� �ȵǾ������� ť�� �ִ´�.
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

	//�׷��� ����
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