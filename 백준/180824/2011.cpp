/*
	��ȣ�ڵ��ص�����
	Ǯ��������
	��ȭ�ĸ���� �����
*/
#include <iostream>
#include <string>
using namespace std;

int dp[5001] = { 0 };

int main()
{
	string input;
	cin >> input;

	dp[0] = 1;

	for (int i = 1; i <= input.size(); i++)
	{
		int x = input[i-1] - '0'; //���ڸ� ���ڷ� ��ȯ
		if (x >= 1 && x <= 9) //���ڸ������̸�
			dp[i] = (dp[i] + dp[i - 1]) % 1000000; //�� ����� ���� ����
		if (i == 1)continue; 
		if (input[i - 2] == '0') continue; //�� �ε����� 0�̸� ������ ���ڸ����̹Ƿ� �Ʒ� �ڵ�� �н�
		int y = (input[i - 2] - '0') * 10 + input[i - 1] - '0'; //���ڸ� ���ڸ� ���ڷ� ��ȯ
		if (y >= 10 && y <= 26) 
			dp[i] = (dp[i] + dp[i - 2]) % 1000000; //���ڸ� �����̸� ���� ����� ���� ����
	}
	printf("%d\n", dp[input.size()]);
	return 0;
}