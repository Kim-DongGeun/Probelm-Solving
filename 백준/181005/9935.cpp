/*
	idea : 스택을이용하여 타겟 단어와 일치하는 인덱스를 저장해두고 타겟단어가 검출되면
			문자열의 인덱스를 
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	bool check[1000001] = { false };
	string input, word;
	stack<pair<int, int>> s; //(문자열의 인덱스, 타겟단어의 인덱스)
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