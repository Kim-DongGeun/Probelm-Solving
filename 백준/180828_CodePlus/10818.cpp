#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	//pair<iterator, iterator> 형으로 반환
	auto it = minmax_element(arr.begin(), arr.end());

	printf("%d %d", *it.first, *it.second);

	return 0;
}