#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int arr[5000000];
	int A, K;

	scanf("%d %d", &A, &K);

	K -= 1;
	for(int i = 0 ; i < A; i++)
	{
		scanf("%d", &arr[i]);
	}

	//���ۺ��� K������ ����
	nth_element(arr, arr + K, arr + A);

	printf("%d\n", arr[K]);
	return 0;
}