#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cnt[100001];
vector<int> map[100001];
bool check[100001];
queue<int> q;

int N, num, a, b;
pair<int, int> ans;


int main()
{
	scanf("%d", &N);

	//맵
	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &num);
		while (true)
		{
			scanf("%d", &a);
			if (a == -1) break;
			scanf("%d", &b);

			map[num].push_back(a);//정점
			map[num].push_back(b);//가중치
		}
	}

	//bfs
	q.push(1);

	while (!q.empty())
	{
		int x = q.front();
		check[x] = true;
		q.pop();

		for (int j = 0; j < map[x].size(); j += 2)
		{
			int next = map[x][j];
			if (check[next] == false)
			{
				q.push(next);
				cnt[next] = cnt[x] + map[x][j + 1];
				if(ans.first != max(ans.first, cnt[next]))
					ans = make_pair(max(ans.first, cnt[next]), next);
			}
		}
	}
	
	for (int j = 1; j <= N; j++)
	{
		check[j] = false;
		cnt[j] = 0;
	}

	
	q.push(ans.second);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		check[x] = true;

		for (int j = 0; j < map[x].size(); j += 2)
		{
			int next = map[x][j];
			if (check[next] == false)
			{
				q.push(next);
				cnt[next] = cnt[x] + map[x][j + 1];
				ans.first = max(ans.first, cnt[next]);
			}
		}
	}

	printf("%d\n", ans.first);

	return 0;
}