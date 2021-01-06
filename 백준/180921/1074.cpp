/*
	idea : 4������� ������鼭 Ÿ�� ��ǥ�� �ƴϸ� �Ѿ�鼭 
		   ī��Ʈ���ش�.
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