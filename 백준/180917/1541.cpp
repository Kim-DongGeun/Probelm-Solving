/*
	idea : 마이너스 뒤에 있는 숫자는 모두 괄호처리하여 마이너스 연산으로 바꾼다. 그러면 최솟값이 나옴
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> num;
vector<int> sign;

int main()
{
	string input;
	cin >> input;

	int cur = 0;
	sign.push_back(1); //우선 +를 넣어둠

	//부호를 제크하면서 숫자를 저장함
	for (char x : input)
	{
		if (x == '+' || x == '-') //부호면 부호벡터에 추가
		{
			if (x == '+')
				sign.push_back(1);
			else
				sign.push_back(-1);
			num.push_back(cur);
			cur = 0;
		}
		else //숫자면 숫자저장
		{
			cur = 10 * cur + (x - '0');
		}
	}
	num.push_back(cur); //마지막 숫자를 넣어줌

	int ans = 0;
	bool minus = false;
	for (int i = 0; i < num.size(); i++)
	{
		if (sign[i] == -1) //마이너스면 이후에 숫자는 전부 마이너스
			minus = true;

		if (minus) ans -= num[i];
		else ans += num[i];
	}
	printf("%d\n", ans);
	return 0;
}