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
		if (salaries[i] == 0)//���� ����Ǿ� ���� ������
		{
			long long total = 0;

			for (int j = 0; j < relations[i].size(); j++)
			{
				if (relations[i][j] == 'Y')
				{
					total += getSalary(j, relations);
				}
			}

			if (total == 0) total = 1; //���ϰ� ������ �޿� 1
			salaries[i] = total; //�޿� ����
		}
		return salaries[i];
	}
};