#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	vector<int> arr(1000000);
	int N; 
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.begin() + N);
	for (int i = 0 ; i< N; i++)
		printf("%d\n", arr[i]);
	return 0;
}