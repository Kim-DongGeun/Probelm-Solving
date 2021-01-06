#include <iostream>
using namespace std;

void cal(int sum, int b)
{
	if (sum == 0)return;
	cal(sum / b, b);
	printf("%d ", (sum % b));
}

int main()
{
	int A, B, n;
	cin >> A >> B;

	cin >> n;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		ans = ans * A + x;
	}

	cal(ans, B);
	return 0;
}