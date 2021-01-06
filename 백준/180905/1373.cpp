#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string input, ans = "";
	cin >> input;

	reverse(input.begin(), input.end());

	if (input.length() % 3 == 1)
	{
		input.push_back('0');
		input.push_back('0');
	}
	else if(input.length() % 3 == 2)
		input.push_back('0');

	

	for (int i = 0; i < input.length(); i += 3)
	{
		string temp = input.substr(i, 3);
		ans += (char)(((temp[0] - '0') + (temp[1] - '0') * 2 + (temp[2] - '0') * 4) + '0');
	}
	reverse(ans.begin(), ans.end());
	printf("%s\n", ans.c_str());
	return 0;
}