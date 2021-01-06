#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string cal(char a)
{
	string temp = "";
	int A = a - '0';
	for (int i = 0; i < 3; i++)
	{
		temp += to_string(A % 2);
		A /= 2;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}

int main()
{
	string ans = "", input;

	cin >> input;

	int n = input.length();

	for (int i = 0; i < n; i++)
	{
		ans += cal(input[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		if (ans[0] == '0')
			ans = ans.substr(1);
		else
			break;
	}
	cout << ans << "\n";
	return 0;
}