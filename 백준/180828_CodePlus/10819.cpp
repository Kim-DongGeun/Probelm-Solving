#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int N, answer = 0;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());

	do
	{
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
			sum += abs(arr[i] - arr[i + 1]);

		answer = max(answer, sum);
	} while (next_permutation(arr.begin(), arr.end()));


	printf("%d\n", answer);
	return 0;
}