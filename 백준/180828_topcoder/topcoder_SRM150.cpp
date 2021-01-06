#include <iostream>
#include <vector>
using namespace std;

class InterestingDigits {
public:
	vector<int> digits(int base)
	{
		vector<int> ans;

		for (int i = 2; i < base; i++)
		{
			bool check = true;
			for (int h = 2; h < base; h++)
			{
				for (int t = 2; t < base; t++)
				{
					for (int o = 2; o < base; o++)
					{
						if ((base * base * h + base * t + o) % i == 0 && (h + t + o) % i != 0)
						{
							check = false;
							break;
						}
					}
					if (!check)break;
				}
				if (!check) break;
			}
			if (check)ans.push_back(i);
		}
		return ans;

		//수학적 계산 
		//a x n^2 + b x n + c = ((a x (n-1) + b + 2a) x (n-1)) + (a + b + c)
		//n-1과 그의 약수가 답
		/*for (int i = 2; i < base; i++)
			if ((base - 1) % i == 0)ans.push_back(i);
		return ans;*/

	}
};

int main()
{
	return 0;
}