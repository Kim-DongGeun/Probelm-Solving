#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int main()
{
	int A, P;

	scanf("%d %d", &A, &P);

	vector<long long> arr;
	arr.push_back(A);

	bool out = false;
	int ans;

	while (true)
	{
		long long temp = 0;
		string a = to_string(arr[arr.size() - 1]);
		for (int i = 0; i < a.length(); i++)
		{
			temp += (long long)pow((a[i] - '0'), P);
		}

		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] == temp) {
				out = true;
				ans = i;
			}
		}

		arr.push_back(temp);

		if (out)break;
	}
	printf("%d\n", ans);
	return 0;
}