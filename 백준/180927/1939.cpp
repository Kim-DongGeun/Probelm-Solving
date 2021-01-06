/*
	idea : 정답이 무조건있는 데이터가 입력되므로 중량을 정렬하여 이분탐색하면서 현재 중량으로 목적지까지 갈수있으면
		   증량 아니면 감량하면서 최대중량을 찾는다.
*/
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[100001];
vector<pair<int, int>>arr[100001]; //to, weight
vector<int> Weight;

int main()
{
	int N, M;
	set<int> weigth;
	scanf("%d %d", &N, &M);

	int a, b, c;
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
		weigth.insert(c);
		visited[i] = false;
	}

	int from, to;
	scanf("%d %d", &from, &to);

	for (auto x : weigth)
		Weight.push_back(x);

	int high = Weight.size() - 1;
	int low = 0;
	int ans = 0;
	
	queue<pair<int, int>> q;

	while (low <= high)
	{
		bool found = false;
		int mid = (low + high) / 2;

		while (!q.empty()) q.pop();
		for (int i = 1; i <= N; i++)
			visited[i] = false;

		for (auto x : arr[from])
			q.push(x);
		visited[from] = true;

		while (!q.empty())
		{
			int cur = q.front().first;
			int cur_weight = q.front().second;
			q.pop();

			if (cur_weight < Weight[mid]) continue;
			if (cur == to) {
				found = true;
				break;
			}

			if (visited[cur]) continue;

			for (auto next : arr[cur])
				q.push(next);
			visited[cur] = true;
		}

		if (found) {
			ans = max(ans, Weight[mid]);
			low = mid + 1;
		}
		else high = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}