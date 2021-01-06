/*
	idea : 1 ~ n-1 ž�� ��ĭ���� �ű�� n�� �������� �ű� �� 1 ~ n-1�� �������� �ű��.
		   ��������� ���鼭 �������� ���Ϳ� �߰�
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