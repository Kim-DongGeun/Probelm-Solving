/*
	idea : �������̿��Ͽ� Ÿ�� �ܾ�� ��ġ�ϴ� �ε����� �����صΰ� Ÿ�ٴܾ ����Ǹ�
			���ڿ��� �ε����� 
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	bool check[1000001] = { false };
	string input, word;
	stack<pair<int, int>> s; //(���ڿ��� �ε���, Ÿ�ٴܾ��� �ε���)
	cin >> input >> word;
	if (word.length() == 1)
	{
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == word[0])
				check[i] = true;
		}
	}
	else
	{
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == word[0]) s.push({ i, 0 });
			else {
				if (!s.empty())
				{
					auto x = s.top();
					if (input[i] == word[x.second + 1])
					{
						s.push({ i, x.second + 1 });
						if (x.second + 1 == word.length() - 1)
						{
							for (int j = 0; j < word.length(); j++)
							{
								check[s.top().first] = true;
								s.pop();
							}
						}
					}
					else
					{
						while (!s.empty()) s.pop();
					}
				}
			}
		}
	}
	bool print = false;
	for (int i = 0; i < input.length(); i++)
		if (!check[i]) {
			printf("%c", input[i]);
			print = true;
		}
	if (!print) printf("FRULA\n");
	return 0;
}