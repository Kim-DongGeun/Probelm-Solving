#include <iostream>
#include <string>
#include <list>
using namespace std;

list<char> arr;

int main()
{
	char a[4];
	string input;
	int N;

	cin >> input;

	for (int i = 0; i < input.length(); i++)
		arr.push_back(input[i]);

	scanf("%d", &N);
	
	list<char>::iterator iter = arr.end();

	while (N--)
	{
		scanf(" %[^\n]", a);

		switch (a[0])
		{
		case 'P':
			arr.insert(iter, a[2]);
			break;
		case 'L':
			if (iter != arr.begin())
				--iter;
			break;
		case 'D':
			if (iter != arr.end())
				++iter;
			break;
		case 'B':
			if (iter != arr.begin())
			{
				--iter;
				iter = arr.erase(iter);
			}
			break;
		}
	}

	for (iter = arr.begin(); iter != arr.end(); ++iter)
		printf("%c", *iter);

	return 0;
}