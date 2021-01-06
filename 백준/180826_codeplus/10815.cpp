#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N, a;
	set<int> arr;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		arr.insert(a);
	}

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		cout << arr.count(a) << ' ';
	}

	return 0;
}