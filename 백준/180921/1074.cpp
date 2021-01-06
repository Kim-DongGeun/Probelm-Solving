/*
	idea : 4등분으로 나누어가면서 타겟 좌표가 아니면 넘어가면서 
		   카운트해준다.
*/
#include <iostream>
#include <math.h>
using namespace std;

int ans = 0;
int N, r, c;

void solve(int x, int y, int n)
{
	if (n == 2)
	{
		if (r == y && c == x)
		{
			printf("%d\n", ans++);
			return;
		}
		ans++;
		if (r == y && c == x + 1)
		{
			printf("%d\n", ans++);
			return;
		}
		ans++;
		if (r == y + 1 && c == x)
		{
			printf("%d\n", ans++);
			return;
		}
		ans++;
		if (r == y + 1 && c == x + 1)
		{
			printf("%d\n", ans++);
			return;
		}
		ans++;
		return;
	}

	solve(x, y, n / 2);
	solve(x + n / 2, y, n / 2);
	solve(x, y + n / 2, n / 2);
	solve(x + n / 2, y + n / 2, n / 2);
}

int main()
{
	scanf("%d %d %d", &N, &r, &c);

	solve(0, 0, (int)pow(2, N));

	return 0;
}