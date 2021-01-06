/*
	idea : 정렬해서 절대값이 큰값끼리 묶어서 계산함
			0은 음수를 하나 상쇄시킬수 있고 1은 곱하는 것 보다 1더하기를 한다
			자료구조를 활용하자
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main()
{
	
	priority_queue<int> positive;
	priority_queue<int> negative;
	int N, zero = 0, one = 0, a;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		if (a < 0)
			negative.push(a);
		else if (a == 1)
			one++;
		else if (a > 0)
			positive.push(a);
		else
			zero++;
	}

	if (positive.size() % 2 == 1) positive.push(1);
	if (negative.size() % 2 == 1)
		zero ? negative.push(0) : negative.push(1);

	int ans = 0;

	int ps = positive.size() / 2;
	int ns = negative.size() / 2;

	for (int i = 0; i < ps; i++)
	{
		int temp = positive.top();
		positive.pop();
		int multi = temp * positive.top();
		positive.pop();
		ans += multi;
	}
	for (int i = 0; i < ns; i++)
	{
		int temp = negative.top();
		negative.pop();
		int multi = temp * negative.top();
		negative.pop();
		ans += multi;
	}

	printf("%d\n", ans + one);
	return 0;
}