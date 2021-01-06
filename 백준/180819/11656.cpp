#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string input;
	
	getline(cin, input);

	string* arr = new string[input.length()];

	for (int i = 0; i < input.length(); i++)
		arr[i] = input.substr(i);

	sort(arr, arr + input.length());

	for (int i = 0; i < input.length(); i++)
		printf("%s\n", arr[i].c_str());

	return 0;
}