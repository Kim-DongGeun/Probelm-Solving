#include <iostream>
#include <algorithm>
using namespace std;


struct XY
{
	int x;
	int y;
};
/*
int partition(XY* a, int low, int high)
{
	int pivotIdx = (low + high) / 2;

	pivotIdx = high;
	for (int idx = low; idx <= high; idx++)
	{
		if (a[idx].x > a[pivotIdx].x && pivotIdx > idx)
		{
			swap(a[idx], a[pivotIdx]);
		}
		else if (a[idx].x < a[pivotIdx].x && pivotIdx < idx)
		{
			swap(a[idx], a[pivotIdx]);
		}
	}

	return pivotIdx;
}

void quicksort(XY* a, int low, int high)
{
	if (low < high)
	{
		int pivotIdx = partition(a, low, high);

		quicksort(a, low, pivotIdx - 1);
		quicksort(a, pivotIdx + 1, high);
	}
}
*/ 
bool compare(XY a, XY b)
{
	if (a.x < b.x)
		return true;
	else if (a.x == b.x)
		return a.y < b.y;
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

	//quicksort(xy, 0, N - 1);
	//구조체를 퀵소트에 넣어서 해봣지만 계속 시간초과가남

	sort(xy, xy + N, compare);
	//algorithm 헤더에 sort함수 에서 compare함수를 조건으로 사용

	/*for (int i = 0; i < N-1; i++)
	{
		if (xy[i].x == xy[i + 1].x && xy[i].y > xy[i + 1].y)
			swap(xy[i], xy[i + 1]);
	}*/

	for (int i = 0; i < N; i++)
		printf("%d %d\n", xy[i].x, xy[i].y);

	return 0;
}