#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



struct Person
{
	int age;
	string name;
};

bool cmp(const Person &a, const Person &b)
{
	return a.age < b.age;
}

int main()
{
	vector<Person> arr(1000000);
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].age >> arr[i].name;
	}

	stable_sort(arr.begin(), arr.begin() + N, cmp);

	for (int i = 0; i < N; i++)
	{
		printf("%d %s\n", arr[i].age, arr[i].name.c_str());
	}
	return 0;
}