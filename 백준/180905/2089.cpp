#include <iostream>
#include <algorithm>
using namespace std;

string ans = "";

int main()
{
	int N;

	scanf("%d", &N);

	if (N == 0)
	{
		printf("0\n");
		return 0;
	}
	else {
		while (N != 0)
		{
			int m;
			if (N % 2 == 0)
			{
				m = -(N / 2);
				ans += '0';
			}
			else
			{
				if (N > 0)
					m = -(N / 2);
				else
					m = (-N + 1) / 2;
				ans += '1';
			}
			N = m;
		}
	}
	reverse(ans.begin(), ans.end());
	printf("%s\n", ans.c_str());
	return 0;
}