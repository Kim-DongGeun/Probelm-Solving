#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//정점, 거리
vector<pair<int, int>> arr[100001];
pair<bool, int> check[100001];


//트리의 지름 임의의 점에서 가장먼 정점과 그 정점에서 가장먼 거리가 지름
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int n, a, b;
		scanf("%d", &n);
		while (true)
		{
			scanf("%d", &a);
			if (a == -1)break;
			scanf("%d", &b);

			arr[n].push_back({ a,b });
		}
		check[i].first = false;
		check[i].second = 0;
	}

	queue<int> q;

	q.push(1);
	check[1].first = true;

	int path = 0;
	int index = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (pair<int, int> a : arr[x])
		{
			if (check[a.first].first == false) {
				check[a.first].first = true;
				check[a.first].second = check[x].second + a.second;
				q.push(a.first);
				if (path != max(path, check[a.first].second))
				{
					path = max(path, check[a.first].second);
					index = a.first;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		check[i].first = false;
		check[i].second = 0;
	}

	q.push(index);
	check[index].first = true;

	path = 0;
	index = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (pair<int, int> a : arr[x])
		{
			if (check[a.first].first == false) {
				check[a.first].first = true;
				check[a.first].second = check[x].second + a.second;
				q.push(a.first);
				if (path != max(path, check[a.first].second))
				{
					path = max(path, check[a.first].second);
					index = a.first;
				}
			}
		}
	}

	printf("%d\n", path);
	return 0;
}