#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string input;
	cin >> input;

	if (find(input.begin(), input.end(), '0') != input.end())
	{
		int sum = 0;
		int n = input.length();
		for (int i = 0; i < n; i++)
			sum += input[i] - '0';

		if (sum % 3 == 0)
		{
			sort(input.begin(), input.end(), greater<int>());
			printf("%s\n", input.c_str());
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}