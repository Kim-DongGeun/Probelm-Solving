#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> arr;
	int N, a;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a;

		if (a == 0)
		{
			if (arr.empty())
				cout << 0 << "\n";
			else
			{
				cout << arr.top() << endl;
				arr.pop();
			}
		}
		else
		{
			arr.push(a);
		}
	}
	return 0;
}