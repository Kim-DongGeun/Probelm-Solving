//[DP] �޿� ����
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
		if (salary[i] == 0) //����� ���� ������ ���
		{
			long long sal = 0;
			for (int j = 0; j < relations.size(); j++)
			{
				if (relations[j] == "Y")
					sal += GetSalary(j, relations); //����ϸ鼭 ���������� �޿��� ��� ���Ѵ�
			}
			if (sal == 0) //���ϰ� ���� �����̸� �޿��� 1
				sal = 1;

			salary[i] = sal; //����� ���� �迭�� �־��ش�.
		}
		
		return salary[i]; //����Ǿ������� ����Ȱ��� ��ȯ
	}
};


int main()
{
	return 0;
}