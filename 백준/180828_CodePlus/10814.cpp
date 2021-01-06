#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main()
{
	int N;
	cin >> N;

	vector<pair<int, string>> arr(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;

	// 비교값이 같을 시 입력 순서를 유지함
	stable_sort(arr.begin(), arr.end(), [](pair<int, string> a, pair<int, string> b)
	{
		return a.first < b.first;
	});

	for (pair<int, string> x : arr)
		cout << x.first << ' ' << x.second << "\n";

	return 0;
}