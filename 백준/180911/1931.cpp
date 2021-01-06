/*
	idea : 회의가 끝나는데로 가장 가까운시간에 시작하는 회의를 찾는다.
	회의시작이 같으면 끝나는 시간이 빠른걸로 선택
*/
#include <iostream>
#include <algorithm>
using namespace std;


bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
}

pair<int, int> map[100000];

int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &map[i].first, &map[i].second);

	sort(map, map + N, cmp);


	int ans = 0;
	int now = 0;
	for (int i = 0; i < N; i++)
	{
		if (now <= map[i].first)
		{
			now = map[i].second;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}