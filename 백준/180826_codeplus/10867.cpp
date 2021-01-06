#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> arr;
	int N, a;

	cin >> N;
	
	while (N--)
	{
		cin >> a;
		arr.insert(a);
	}

	for (auto it = arr.begin(); it != arr.end(); ++it)
		cout << *it << ' ';


	return 0;
}