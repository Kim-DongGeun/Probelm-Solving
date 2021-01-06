#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	set<string> arr;
	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		arr.insert(input.substr(i));
	}

	for (string x : arr)
		printf("%s\n", x.c_str());

	return 0;
}