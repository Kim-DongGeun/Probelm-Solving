#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, a;
	cin >> N;
	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		arr[i] = a;
	}

	sort(arr.begin(), arr.end());

	for (int x : arr)
		cout << x << "\n";


	return 0;
}