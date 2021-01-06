#include <iostream>
#include <string>
#include <string.h> //memset
using namespace std;

int main()
{
	int arr[26];
	memset(arr, -1, sizeof(arr));
	string input;
	cin >> input;

	for (int i = input.length() - 1; i >= 0; i--)
	{
		arr[input[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", arr[i]);

	return 0;
}