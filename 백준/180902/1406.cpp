#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<char> R;
	stack<char>	L;
	string c;
	char order;
	int N;

	cin >> c;
	scanf("%d", &N);

	for (int i = 0; i < c.length(); i++)
		L.push(c[i]);

	while (N--)
	{
		scanf(" %c", &order);

		if (order == 'P')
		{
			char input;
			scanf(" %c", &input);
			L.push(input);
		}
		else if (order == 'L')
		{
			if (!L.empty())
			{
				R.push(L.top());
				L.pop();
			}
		}
		else if (order == 'D')
		{
			if (!R.empty())
			{
				L.push(R.top());
				R.pop();
			}
		}
		else if (order == 'B')
		{
			if (!L.empty())
				L.pop();
		}
	}
	while (!L.empty())
	{
		R.push(L.top());
		L.pop();
	}
	
	while(!R.empty())
	{
		printf("%c", R.top());
		R.pop();
	}
	return 0;
}