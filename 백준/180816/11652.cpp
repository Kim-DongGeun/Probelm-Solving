#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	long long* arr = new long long[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	long long answer;
	int count = 1;
	int maxCount = 0;


	for (int i = 1; i < N; i++)
	{
		if (arr[i - 1] == arr[i])
			count++;
		else if (arr[i - 1] != arr[i] && maxCount < count)
		{
			maxCount = count;
			answer = arr[i - 1];
			count = 1;
		}
		else if (arr[i - 1] != arr[i] && maxCount >= count)
			count = 1;

	}

	if (maxCount < count)
		answer = arr[N - 1];

	cout << answer << "\n";


	return 0;
}