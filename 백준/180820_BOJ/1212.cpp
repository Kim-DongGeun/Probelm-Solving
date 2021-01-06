#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string cal(int a)
{
	string answer = "";
	for (int i = 0; i < 3; i++)
	{
		answer += to_string(a % 2);
		a /= 2;
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

int main()
{
	char a[333335];
	string input = "";
	scanf("%s", a);

	int num = strlen(a);

	for (int i = 0; i < num; i++)
		input += cal(a[i]-'0');

	if (input[0] == '0')
	{
		if (input[1] == '0')
		{
			printf("%s\n", input.substr(2).c_str());
			return 0;
		}
		printf("%s\n", input.substr(1).c_str());
	}
	else
		printf("%s\n", input.c_str());
	return 0;
}