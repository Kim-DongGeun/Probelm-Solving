#include <iostream>
#include <string>
using namespace std;

int dp[5001] = { 1 };

//0으로 시작하는 경우를 생각못해서 많이 틀림
int main()
{
	string input;

	getline(cin, input);

	int size = input.length();
	
	for (int i = 1; i <= size; i++)
	{
		int x = input[i-1] - '0';
		if (x >= 1 && x <= 9)
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;
		if (i == 1)continue;
		x = 10 * (input[i - 2] - '0') + (input[i - 1] - '0');
		if (x >= 10 && x <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
	}
	printf("%d\n", dp[size]);
	return 0;
}