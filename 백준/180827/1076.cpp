#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, int> arr = {
		{"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3},
		{"yellow", 4}, {"green", 5}, {"blue", 6}, {"violet", 7}, {"grey", 8}, {"white", 9} 
	};

	string a, b, c;
	cin >> a >> b >> c;

	long long ans = (long long)(10 * arr[a] + arr[b]);

	for (int i = 0; i < arr[c]; i++)
		ans *= 10;

	cout << ans << "\n";

	return 0;
}