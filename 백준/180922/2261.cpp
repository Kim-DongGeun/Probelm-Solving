/*
	Ǯ�̸� ���� ���ذ� �Ȱ�
*/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

int inf = 100000000;

typedef pair<int, int> Point;

double dist(Point a, Point b)
{
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	return (dx*dx) + (dy*dy);
}

bool cmp(Point &a, Point &b)
{
	return a.first < b.first;
}

int main()
{
	int N;
	scanf("%d", &N);
	map<Point, int> mp;
	vector<Point> arr(N);

	for (auto iter = arr.begin(); iter != arr.end(); iter++) {
		cin >> iter->first >> iter->second;
	}
	//x���� ���� ����
	sort(arr.begin(), arr.end(), cmp);
	//ó���ΰ��� xy��ǥ ����
	
	mp[{arr[0].second, arr[0].first}] = 1;
	mp[{arr[1].second, arr[1].first}] = 1;
	
	//�켱 �ּҰŸ���� ����
	double ans = dist(arr[0], arr[1]);

	int last = 0;
	

	for (int i = 2; i < N; i++)
	{
		while (last < i)
		{
			int d = arr[i].first - arr[last].first;
			//�ּҰŸ����� ������ ����
			if (d*d <= ans) break;
			//�ּҰŸ����� ū �� last�� map���� ����
			mp.erase({ arr[last].second, arr[last].first });
			last++;
		}

		int limit = (int)sqrt(ans);

		
		auto lo = mp.lower_bound({ arr[i].second - limit, -inf });
		auto up = mp.upper_bound({ arr[i].second - limit, inf });

		for (auto it = lo; it != up; it++) {
			ans = min(ans, dist({ it->first.second, it->first.first }, arr[i]));
		}

		mp[{arr[i].second, arr[i].first}] = 1;
	}

	printf("%d\n", (int)ans);
	return 0;
}