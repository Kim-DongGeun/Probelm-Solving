#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	string A, B;

	A = to_string(a) + to_string(b);
	B = to_string(c) + to_string(d);

	long long ans = stoll(A) + stoll(B);

	printf("%lld\n", ans);
	return 0;
}