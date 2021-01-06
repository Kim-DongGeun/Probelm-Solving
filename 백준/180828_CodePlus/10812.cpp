#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, first, mid, last;
	cin >> N >> M;

	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;

	for (int i = 0; i < M; i++)
	{
		cin >> first >> last >> mid;
		rotate(arr.begin() + first - 1, arr.begin() + mid - 1, arr.begin() + last);
	}

	for (int x : arr)
		cout << x << ' ';
	return 0;
}