#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	cin >> input;
	int arr[26];
	std::fill_n(arr, 26, -1);

	for (int i = 0; i < input.length(); i++)
	{
		int index = input.find(input[i]);
		arr[input[i] - 'a'] = index;
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}