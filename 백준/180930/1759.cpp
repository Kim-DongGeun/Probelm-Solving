/*
	idea : ����Լ��� ������ ���ؾ��Ѵ�.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> ans;

void go(int n, vector<char> &alpha, string password, int index)
{
	if (n == password.length()) {
		int jaum = 0;
		int moum = 0;
		for (auto x : password)
		{
			if (x == 'a' || x == 'e' || x == 'i' || x == 'u' || x == 'o') moum++;
			else jaum++;
		}
		if (jaum >= 2 && moum >= 1)
			printf("%s\n", password.c_str());
		return;
	}
	if (index >= alpha.size()) return;

	
	go(n, alpha, password + alpha[index], index + 1); //index�� ���ĺ��� ����ϴ� ���
	go(n, alpha, password, index + 1); //index�� ���ĺ��� �����ϴ°��
}

int main()
{
	int L, C;
	scanf("%d %d", &L, &C);
	vector<char> alpha(C);

	for (int i = 0; i < C; i++)
		scanf("%s", &alpha[i]);

	sort(alpha.begin(), alpha.end());

	go(L, alpha, "", 0);

	return 0;
}