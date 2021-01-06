#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Cryptography {
public:
	long long encrypt(vector<int> numbers)
	{
		long long answer = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			long long sum = 0;
			numbers[i]++;
			for (int j = 0; j < numbers.size(); j++)
			{
				sum *= numbers[j];
			}
			numbers[i]--;
			answer = max(answer, sum);
		}
		return answer;

		//젤 작은 수에 1을 더한것이 답 
		/*sort(numbers.begin(), numbers.end());
		numbers[0]++;

		for (int i = 0; i < numbers.size(); i++)
			answer *= numbers[i];
		return answer;*/

	}
};

int main()
{
	return 0;
}