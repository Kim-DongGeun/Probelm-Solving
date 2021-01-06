#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int input, arr[1000001];

	cin >> input;
	
	arr[1] = 0; // 초기조건 1일때는 최솟값 0

	for (int i = 2; i <= input; i++)
	{
		arr[i] = arr[i - 1] + 1; //우선 1뺀 경우의 수의 1을 더한값을 넣어둔다
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1); //3으로 나누어질 떄 1로 뺀 경우와 비교해서 더 작은 값을 넣음
		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1); //2로 나누어질 떄 1로 뺀 경우와 비교해서 더 작은 값을 넣음
	}

	cout << arr[input] << "\n";

	return 0;
}