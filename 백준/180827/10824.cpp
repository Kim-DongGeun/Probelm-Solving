#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;

	long long A = stoll(a+b);
	long long B = stoll(c+d);

	cout << A + B << "\n";

	return 0;
}