#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	string input;
	cin >> N;
	vector<string> arr(N, "");

	for (int i = 0; i < N; i++)
	{
		cin >> input;;
		arr[i] = input;
	}

	sort(arr.begin(), arr.end(), [](string a, string b)
	{
		if (a.size() == b.size())
			return a < b;
		else
			return a.size() < b.size();
	}
	);

	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (string x : arr)
		cout << x << "\n";


	return 0;
}