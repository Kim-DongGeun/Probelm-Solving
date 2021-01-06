#include <iostream>
#include <string>
#include <list>
using namespace std;


int main()
{
	char a;
	string input;
	int N;

	cin >> input;
	list<char> arr(input.begin(), input.end());

	cin >> N;

	auto iter = arr.end();

	while (N--)
	{
		cin >> a;

		switch (a)
		{
		case 'P':
			cin >> a;
			arr.insert(iter, a);
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

	for (auto &a : arr)
		printf("%c", a);

	return 0;
}