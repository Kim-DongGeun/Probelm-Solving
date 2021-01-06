#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long long N;
	int answer[33] = { 0, }, count = 0;
	bool first = true;
	cin >> N;

	if (N == 0)
	{
		printf("0");
		return 0;
	}
	

	while (N != 0)
	{
		if (N < 0) //음수
		{
			int index = 1;
			long long num = (long long)pow(-2, index);
			while (N < num)
			{
				index += 2;
				num += (long long)pow(-2, index);
			}
			if (first)
			{
				count = index;
				first = false;
			}
			answer[index] = 1;
			N -= (long long)pow(-2, index);
		}
		else //양수
		{
			int index = 0;
			long long num = (long long)pow(2, index);
			while (N > num)
			{
				index += 2;
				num += (long long)pow(2, index);
			}
			if (first)
			{
				count = index;
				first = false;
			}
			answer[index] = 1;
			N -= (long long)pow(2, index);
		}
	}

	while (count != -1)
		printf("%d", answer[count--]);

	return 0;
}