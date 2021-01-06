#include <iostream>
#include <algorithm>
using namespace std;

struct XY
{
	int x;
	int y;
};

bool compare(XY a, XY b)
{
	if (a.y < b.y)
		return true;
	else if (a.y == b.y)
		return a.x < b.x;
	else
		return false;
}

int main()
{
	int N;
	cin >> N;

	XY xy[100000];

	for (int i = 0; i < N; i++)
		cin >> xy[i].x >> xy[i].y;
	
	sort(xy, xy + N, compare);

	for (int i = 0; i < N; i++)
		printf("%d %d\n", xy[i].x, xy[i].y);

	return 0;
}