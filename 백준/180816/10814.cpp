#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct XY
{
	int x;
	string y;
	int z;
};

bool compare(XY a, XY b)
{
	if (a.x < b.x)
		return true;
	else if (a.x == b.x)
		return a.z < b.z;
	else
		return false;
}

int main()
{
	int N;
	cin >> N;

	XY* xy = new XY[N];

	for (int i = 0; i < N; i++) {
		cin >> xy[i].x >> xy[i].y;
		xy[i].z = i;
	}
	
	sort(xy, xy + N, compare);

	for (int i = 0; i < N; i++)
		printf("%d %s\n", xy[i].x, xy[i].y.c_str());

	return 0;
}