#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long salaries[50] = { 0 };

class CorporationSalary {
public:
	long long totalSalary(vector<string> relations)
	{
		long long totalSalary = 0;
		for (int i = 0; i < relations.size(); i++)
		{
			totalSalary += getSalary(i, relations);
		}
		return totalSalary;
	}

	long long getSalary(int i , vector<string> relations)
	{
		if (salaries[i] == 0)//값이 저장되어 있지 않으면
		{
			long long total = 0;

			for (int j = 0; j < relations[i].size(); j++)
			{
				if (relations[i][j] == 'Y')
				{
					total += getSalary(j, relations);
				}
			}

			if (total == 0) total = 1; //부하가 없으면 급여 1
			salaries[i] = total; //급여 저장
		}
		return salaries[i];
	}
};