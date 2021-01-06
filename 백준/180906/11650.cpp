#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first < b.first;
}


int main()
{
	vector<pair<int,int>> arr(100000);
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	sort(arr.begin(), arr.begin() + N , cmp);
	
	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", arr[i].first, arr[i].second);
	}
	return 0;
}