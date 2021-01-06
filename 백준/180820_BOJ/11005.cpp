#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string cal(long long N, int B, string &answer)
{
	if ((N % B) < 10)
		answer += to_string(N % B);
	else
		answer += (char)(N % B + 55);
	if (N / B == 0)
		return answer;
	return cal(N / B, B, answer);
}


int main()
{
	long long N;
	string answer = "";
	int B;
	cin >> N >> B;

	answer = cal(N, B, answer);

	reverse(answer.begin(), answer.end());

	printf("%s\n", answer.c_str());
	return 0;
}