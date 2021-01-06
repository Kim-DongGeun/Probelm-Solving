#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, first, last;
	cin >> N >> M;

	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;

	for (int i = 0; i < M; i++)
	{
		cin >> first >> last;
		swap(arr[first-1], arr[last-1]);
	}

	for (int x : arr)
		cout << x << ' ';
	return 0;
}