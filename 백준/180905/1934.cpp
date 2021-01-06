#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)return a;
	else
		gcd(b, a%b);
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", a*b/gcd(a, b));
	}
	return 0;
}