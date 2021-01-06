#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr;

	int N, M, index = -1;

	cin >> N >> M;

	

	for (int i = 0; i < N; i++)
		arr.push_back(i + 1);

	printf("<");
	while (arr.size() != 1)
	{
		index = (index + M) % arr.size();
		printf("%d, ", arr[index]);

		arr.erase(arr.begin() + index);
		index--;
	}
	printf("%d>\n", arr[0]);

	return 0;
}