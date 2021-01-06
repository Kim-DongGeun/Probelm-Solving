#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

vector<pair<int, int>> Arr;

int main()
{
	map<int, int> arr;
	int N, a;
	scanf("%d", &N);

	//map에 숫자와 빈도를 저장
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a);
		arr[a]++;
	}
	//map -> vector
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		Arr.push_back({ (*it).first, (*it).second });
	}

	int M, target, L = Arr.size();
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		int found = 0;
		int small = 0;
		int big = L-1;

		//binarysearch
		scanf("%d", &target);
		while (small <= big)
		{
			int mid = (big + small) / 2;

			if (Arr[mid].first < target)
				small = mid + 1;
			else if (Arr[mid].first > target)
				big = mid - 1;
			else
			{
				found = Arr[mid].second;
				break;
			}
		}
		printf("%d ", found);
	}
	return 0;
}