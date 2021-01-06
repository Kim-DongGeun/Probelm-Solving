/*
		idea : ��尡 10���ϸ� ����Ž������ �ð��ȿ� Ǯ �� �ִٰ��Ѵ�.
			   ��� ����� ���� �� ��ȸ�ϸ鼭 �ּڰ��� ã��
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M = INT32_MAX;
int map[11][11];
bool check[11] = { false };


void dfs(int start, int cur, int cnt, int sum)
{
	if (map[cur][start] && cnt == N) //���۰� ����Ǿ��ְ� ��ȸ ������ �����̸�
	{
		M = min(M, sum + map[cur][start]); //�ּڰ� ����
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (map[cur][i] && !check[i]) //���±��� �ְ� üũ�� �ȵǾ�������
		{
			check[i] = true; //üũ
			dfs(start, i, cnt + 1, sum + map[cur][i]); //������ �ø��� ���� ����ؼ� dfs
			check[i] = false; //Ž���� üũ ����
		}
	}
}

int main()
{
	
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);

	for (int i = 1; i <= N; i++)
	{
		check[i] = true;
		dfs(i, i, 1, 0);
		check[i] = false;
	}

	printf("%d\n", M);
	return 0;
}