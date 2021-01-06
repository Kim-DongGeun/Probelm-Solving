/*
	암호코드해독문제
	풀이참조함
	점화식만들기 어려움
*/
#include <iostream>
#include <string>
using namespace std;

int dp[5001] = { 0 };

int main()
{
	string input;
	cin >> input;

	dp[0] = 1;

	for (int i = 1; i <= input.size(); i++)
	{
		int x = input[i-1] - '0'; //문자를 숫자로 변환
		if (x >= 1 && x <= 9) //한자리숫자이면
			dp[i] = (dp[i] + dp[i - 1]) % 1000000; //전 경우의 수와 같다
		if (i == 1)continue; 
		if (input[i - 2] == '0') continue; //전 인덱스가 0이면 무조건 한자리수이므로 아래 코드는 패스
		int y = (input[i - 2] - '0') * 10 + input[i - 1] - '0'; //두자리 문자를 숫자로 변환
		if (y >= 10 && y <= 26) 
			dp[i] = (dp[i] + dp[i - 2]) % 1000000; //두자리 숫자이면 전전 경우의 수와 같다
	}
	printf("%d\n", dp[input.size()]);
	return 0;
}