#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

struct person {
	int kor, eng, math;
	string name;
};

int main()
{
	int N;
	
	cin >> N;

	vector<person> arr(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;

	sort(arr.begin(), arr.end(), [](person a, person b)
	{
		//튜플로 비교하면 앞에서부터 차례대로 비교함
		return make_tuple(-a.kor, a.eng, -a.math, a.name) < make_tuple(-b.kor, b.eng, -b.math, b.name);
	});

	for (person x : arr)
		cout << x.name << "\n";
	return 0;
}