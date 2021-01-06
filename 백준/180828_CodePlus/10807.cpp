#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> arr;
	int N,a;
	cin >> N;

	while (N--)
	{
		cin >> a;
		arr.push_back(a);
	}

	cin >> N;

	cout << count(arr.begin(), arr.end(), N) << "\n";
	return 0;
}