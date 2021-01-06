/*
	idea : ȸ�ǰ� �����µ��� ���� �����ð��� �����ϴ� ȸ�Ǹ� ã�´�.
	ȸ�ǽ����� ������ ������ �ð��� �����ɷ� ����
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