#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, first, last;

	cin >> N >> M;

	vector<int> arr;
	for (int i = 1; i <= N; i++)
		arr.push_back(i);

	for (int i = 0; i < M; i++)
	{
		cin >> first >> last;
		reverse(arr.begin() + first - 1, arr.begin() + last);
	}

	for (int x : arr)
		cout << x << ' ';
	return 0;
}