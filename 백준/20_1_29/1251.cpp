#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string input;
	cin >> input;
	string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

	for (int i = 1; i < input.size() - 1; i++) {
		for (int j = 1; (i + j) < input.size(); j++) {
			string temp1 = input.substr(0, i);
			string temp2 = input.substr(i, j);
			string temp3 = input.substr(i + j, input.size() - (i + j));
			reverse(temp1.begin(), temp1.end());
			reverse(temp2.begin(), temp2.end());
			reverse(temp3.begin(), temp3.end());
			temp1 += temp2 + temp3;
			ans = ans > temp1 ? temp1 : ans;
		}
	}
	cout << ans << '\n';
	return 0;
}
