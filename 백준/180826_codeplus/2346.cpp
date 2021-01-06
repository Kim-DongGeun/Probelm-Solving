#include <iostream>
#include <list>
using namespace std;


int main()
{
	list<pair<int,int>> arr;
	int N, a, index = 1;
	cin >> N;

	for(int i = 1 ; i <= N; i++)
	{
		cin >> a;
		arr.push_back({ a, i});
	}

	auto it = arr.begin();
	for (int i = 1; i < N; i++) {
		cout << it->second << ' ';
		int temp = it->first;

		if (temp > 0)
		{
			auto a = it;
			++a;
			if (a == arr.end())
				a = arr.begin();
			arr.erase(it);
			it = a;
			for (int i = 1; i < temp; i++)
			{
				++it;
				if (it == arr.end())
					it = arr.begin();
			}
		}
		else
		{
			auto a = it;
			if (a == arr.begin())
			{
				a = arr.end();
				--a;
			}
			else
				--a;
			arr.erase(it);
			it = a;

			for (int i = 1; i < -temp; i++)
			{
				if (it == arr.begin())
				{
					it = arr.end();
					--it;
				}
				else
					--it;
			}
		}

	}
	cout << arr.begin()->second << "\n";
	return 0;
}