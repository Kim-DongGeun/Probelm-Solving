#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(const pair<long long, int> &a, const pair<long long, int> &b)
{
	return a.second < b.second;
}

int main()
{
	map<long long, int> arr;
	int N;
	long long a;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &a);
		if (arr.find(a) == arr.end())
		{
			arr.insert({ a,1 });
		}
		else
			arr[a]++;
	}
		
	auto it = max_element(arr.begin(), arr.end(), cmp);

	printf("%lld\n", (*it).first);

	return 0;
}