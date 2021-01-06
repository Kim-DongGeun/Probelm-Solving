#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, first, second;
	cin >> N;
	vector<pair<int, int>> arr;

	for (int i = 0; i < N; i++)
	{
		cin >> first >> second;
		arr.push_back(make_pair(first, second));
	}

	sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b)
	{
		if (a.second == b.second)
			return a.first < b.first;
		else
			return a.second < b.second;
	});

	for (pair<int, int> x : arr)
		cout << x.first << ' ' << x.second << "\n";
	return 0;
}