/*
	idea : 1 ~ n-1 탑을 옆칸으로 옮기고 n을 목적지로 옮긴 후 1 ~ n-1을 목적지로 옮긴다.
		   재귀적으로 들어가면서 움직임을 벡터에 추가
*/
#include <iostream>
#include <vector>
using namespace std;

struct xy {
	int x;
	int y;
	xy(int X, int Y) : x(X), y(Y) {};
};
vector<xy> arr;

void solve(int n, int x, int y)
{
	if (n == 0)return;
	solve(n - 1, x, 6 - x - y);
	xy XY(x, y);
	arr.push_back(XY);
	solve(n - 1, 6 - x - y, y);
}

int main()
{
	int N;
	scanf("%d", &N);

	solve(N, 1, 3);

	printf("%d\n", arr.size());
	for (xy XY : arr)
		printf("%d %d\n", XY.x, XY.y);
	return 0;
}