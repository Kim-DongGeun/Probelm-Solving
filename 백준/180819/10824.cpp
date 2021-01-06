#include <iostream>
#include <string>
using namespace std;

int main()
{
	int A, B, C, D;

	cin >> A >> B >> C >> D;

	string a, b;
	a = to_string(A) + to_string(B);
	b = to_string(C) + to_string(D);

	long long answer = strtoll(a.c_str(), 0, 10) + strtoll(b.c_str(), 0, 10);

	cout << answer << "\n";

	return 0;
}