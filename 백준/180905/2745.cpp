#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string N;
	int B;
	cin >> N >> B;

	int ans = 0;
	int n = N.length();

	for(int i= 0 ; i < n; i++)
	{
		if (N[i] >= '0' && N[i] <= '9')
			ans = B * ans + (N[i] - '0');
		else
			ans = B * ans + (N[i] + 10 - 'A');
	}

	printf("%d\n", ans);
	return 0;
}