/*
	idea : 스택을 이용하여 현재 직사각형 보다 높이가 작은 왼쪽 사각형의 인덱스를 찾고
			높이가 작은 오른쪽 사각형중에서 가장 왼쪽의 사각형의 인덱스를 찾아서
			넓이를 구한후 최댓값을 찾는다.
*/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	long long arr[100000] = { 0 };
	long long n, h, ans;
	
	while (scanf("%d", &n) == 1 && n != 0) {
		for (int i = 0; i < n; i++)
			scanf("%lld", &arr[i]);
		stack<long long> s;
		ans = 0;

		for (int i = 0; i < n; i++)
		{
			while (!s.empty() && arr[s.top()] > arr[i]) //다음 높이가 더 작으면
			{
				long long hight = arr[s.top()];
				s.pop();
				long long width = i;
				if (!s.empty()) width = i - 1 - s.top();
				if (ans < hight * width) ans = hight * width;
			}
			s.push(i);
		}
		while (!s.empty())
		{
			long long hight = arr[s.top()];
			s.pop();
			long long width = n;
			if (!s.empty()) width = n - 1 - s.top();
			if (ans < hight * width) ans = hight * width;
		}
		printf("%lld\n", ans);
	}
	return 0;
}