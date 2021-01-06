#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N, B;

	scanf("%d %d", &N, &B);
	string ans = "";

	while (N > 0)
	{
		int r = N % B;
		if (r <= 9)
		{
			ans += (char)(r + '0');
		}
		else
		{
			ans += (char)(r - 10 + 'A');
		}
		N /= B;
	}
	reverse(ans.begin(), ans.end());
	printf("%s\n", ans.c_str());
	return 0;
}