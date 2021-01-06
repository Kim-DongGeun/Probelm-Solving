//[DP] 급여 문제
#include <iostream>
#include <vector>
using namespace std;

long salary[50] = { 0, };

class CorporationSalary
{
public:
	long long totalSalary(vector<string> relations)
	{
		long long total = 0;

		for (int i = 0; i < relations.size(); i++)
			total += GetSalary(i, relations);

		return total;
	}
	long long GetSalary(int i, vector<string> relations)
	{
		if (salary[i] == 0) //저장된 값이 없으면 계산
		{
			long long sal = 0;
			for (int j = 0; j < relations.size(); j++)
			{
				if (relations[j] == "Y")
					sal += GetSalary(j, relations); //재귀하면서 부하직원의 급여를 모두 더한다
			}
			if (sal == 0) //부하가 없는 직원이면 급여는 1
				sal = 1;

			salary[i] = sal; //계산한 값을 배열에 넣어준다.
		}
		
		return salary[i]; //저장되어있으면 저장된값을 반환
	}
};


int main()
{
	return 0;
}