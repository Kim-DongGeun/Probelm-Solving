/*
	idea : dfs, bfs로 풀수있고 유니온파인드를 사용해서도 풀이가 가능한것같다.
			직사각형이 원점에 걸쳐있을 때에는 답에서 -1을 해주어야한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct point {
	int x1, x2, y1, y2;
	point(int X1, int Y1, int X2, int Y2) : x1(X1), x2(X2), y1(Y1), y2(Y2) {};
};

bool cmp(point &a, point &b)
{
	if (a.y1 == b.y1) return a.y2 < b.y2;
	return a.y1 < b.y1;
}

bool cal(point &a, point &b)
{
	if (a.y2 < b.y1 || a.x1 > b.x2 || a.x2 < b.x1) return false;
	else if (a.y2 > b.y2 && a.x1 < b.x1 && a.x2 > b.x2) return false;
	else return true;
}

bool check[1001] = { false };
vector<int> graph[1001];

void dfs(int cur)
{
	check[cur] = true;

	for (auto x : graph[cur])
	{
		if(!check[x])
			dfs(x);
	}
}

int main()
{
	int N, x1, x2, y1, y2;
	vector<point> arr;
	scanf("%d", &N);

	bool zero = false;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		arr.push_back({ x1,y1,x2,y2 });
		if ((y2 >= 0 && y1 <= 0 && x1 == 0) || (y2 >= 0 && y1 <= 0 && x2 == 0)) zero = true;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (cal(arr[i], arr[j])) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (!check[i]) {
			dfs(i);
			ans++;
		}
	}

	if (zero) printf("%d\n", ans - 1);
	else printf("%d\n", ans);
	return 0;
}