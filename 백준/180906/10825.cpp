#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;



struct Person
{
	int kor;
	int eng;
	int math;
	string name;
};

bool cmp(const Person &a, const Person &b)
{
	return make_tuple(-a.kor, a.eng, -a.math, a.name) < make_tuple(-b.kor, b.eng, -b.math, b.name);
}

int main()
{
	vector<Person> arr(1000000);
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;
	}

	sort(arr.begin(), arr.begin() + N, cmp);

	for (int i = 0; i < N; i++)
	{
		printf("%s\n", arr[i].name.c_str());
	}
	return 0;
}