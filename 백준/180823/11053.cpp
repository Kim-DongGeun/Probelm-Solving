/*
	가장긴 증가하는수열의 길이
	풀이 참조함
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, len = 0;
	cin >> N;

	int arr[1001];

	for (int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;

		auto pos = lower_bound(arr + 1, arr + len + 1, input);
		*pos = input;

		if (pos == arr + len + 1)
			len++;
	}
	cout << len << "\n";

	return 0;
}