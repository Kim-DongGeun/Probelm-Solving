#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void cal(long long sum, int B, vector<int> &answer)
{
	answer.push_back((int)(sum % B));
	if (sum / B == 0) return;
	return cal(sum / B, B, answer);
}

int main()
{
	int A, B, N, input;
	vector<int> answer;
	long long sum = 0;
	cin >> A >> B;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		sum += (long long)(input * pow(A, N - i - 1));
	}

	cal(sum, B, answer);

	reverse(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++)
		printf("%d ", answer[i]);

	return 0;
}