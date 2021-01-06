#include <iostream>
using namespace std;


int main()
{
	int N, index;
	cin >> N;
	
	int arr[10001] = { 0, };

	for (int i = 0; i < N; i++)
	{
		cin >> index;
		arr[index]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < arr[i]; j++)
			printf("%d\n", i);
	}

	return 0;
}