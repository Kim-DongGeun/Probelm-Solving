/*
	idea : ���̳ʽ� �ڿ� �ִ� ���ڴ� ��� ��ȣó���Ͽ� ���̳ʽ� �������� �ٲ۴�. �׷��� �ּڰ��� ����
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> num;
vector<int> sign;

int main()
{
	string input;
	cin >> input;

	int cur = 0;
	sign.push_back(1); //�켱 +�� �־��

	//��ȣ�� ��ũ�ϸ鼭 ���ڸ� ������
	for (char x : input)
	{
		if (x == '+' || x == '-') //��ȣ�� ��ȣ���Ϳ� �߰�
		{
			if (x == '+')
				sign.push_back(1);
			else
				sign.push_back(-1);
			num.push_back(cur);
			cur = 0;
		}
		else //���ڸ� ��������
		{
			cur = 10 * cur + (x - '0');
		}
	}
	num.push_back(cur); //������ ���ڸ� �־���

	int ans = 0;
	bool minus = false;
	for (int i = 0; i < num.size(); i++)
	{
		if (sign[i] == -1) //���̳ʽ��� ���Ŀ� ���ڴ� ���� ���̳ʽ�
			minus = true;

		if (minus) ans -= num[i];
		else ans += num[i];
	}
	printf("%d\n", ans);
	return 0;
}