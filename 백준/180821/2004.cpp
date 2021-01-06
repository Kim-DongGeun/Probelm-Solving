#include <iostream>
#include <algorithm>
using namespace std;

long long fNum[3] = { 0, };
long long tNum[3] = { 0, };

void cal(long long  n, int index)
{
	for (long long i = 5; i <= n; i *= 5)
		fNum[index] += n / i;
	for (long long i = 2; i <= n; i *= 2)
		tNum[index] += n / i;
}


int main()
{
	long long n, m;
	cin >> n >> m;

	cal(n, 0);
	cal(m, 1);
	cal(n - m, 2);

	cout << min(fNum[0] - fNum[1] - fNum[2], tNum[0] - tNum[1] - tNum[2]) << "\n";

	return 0;
}