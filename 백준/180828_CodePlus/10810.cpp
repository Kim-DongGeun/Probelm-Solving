#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, first, last, num;
	cin >> N >> M;

	vector<int> arr(N, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> first >> last >> num;
		fill(arr.begin() + first - 1, arr.begin() + last, num);
	}

	for (int x : arr)
		cout << x << ' ';
	return 0;
}