/*
	1,2,3 으로 정수만들기
	점화식 f(n) = f(n-1) + f(n-2) + f(n-3)
*/
#include <iostream>
using namespace std;

int main()
{
	int test_case, input;

	scanf("%d", &test_case);

	while (test_case--)
	{
		int arr[12] = { 0,1,2,4 };
		scanf("%d", &input);

		for (int i = 4; i <= input; i++)
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];

		printf("%d\n", arr[input]);
	}

	
	return 0;
}