#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

long long cal(string N, int B, long long answer)
{
	for (int i = N.length() - 1; i >= 0; i--)
	{
		if(N[i] >= 65 && N[i] <= 90)
			answer += (long long)(pow(B, N.length() - i - 1) * (N[i] - 55));
		else
			answer += (long long)(pow(B, N.length() - 1 - i) * (N[i] - '0'));
	}
	return answer;
}


int main()
{
	long long answer = 0;
	string N;
	int B;
	cin >> N >> B;

	answer = cal(N, B, answer);

	cout << answer << "\n";
	return 0;
}