#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	set<string> s;
	int n;
	scanf("%d", &n);

	string name, log;
	while (n--)
	{
		cin >> name >> log;

		if (log == "enter")
		{
			s.insert(name);
		}
		else
		{
			s.erase(s.find(name));
		}
	}
	for (auto it = s.rbegin(); it != s.rend(); it++)
		printf("%s\n", (*it).c_str());
	return 0;
}