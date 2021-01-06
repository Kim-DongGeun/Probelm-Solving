#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int main()
{
	int N, index = 0;
	scanf("%d", &N);

	arr.push_back(1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < arr.size(); j++)
			arr[j] *= i;

		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[j] / 10 >= 1 && arr.size() - j == 1)
			{
				arr.push_back(arr[j] / 10);
				arr[j] %= 10;
			}
			else if(arr[j] / 10 >= 1)
			{
				arr[j + 1] += arr[j] / 10;
				arr[j] %= 10;
			}
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] != 0) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}