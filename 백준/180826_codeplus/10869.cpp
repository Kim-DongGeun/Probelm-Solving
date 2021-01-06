#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main()
{
	int A, B;
	vector<function<int(int, int)>> d;
	//백터에 연산하는 함수를 넣어둠
	d.push_back([](int a, int b) {
		return a + b;
	});
	d.push_back([](int a, int b) {
		return a - b;
	});
	d.push_back([](int a, int b) {
		return a * b;
	});
	d.push_back([](int a, int b) {
		return a / b;
	});
	d.push_back([](int a, int b) {
		return a % b;
	});

	cin >> A >> B;

	//참조형식으로하여 값복사보다 속도를 높힐수있다.
	//foreach와 유사함
	for (auto &a : d)
	{
		cout << a(A, B) << "\n";
	}
	


	return 0;
}