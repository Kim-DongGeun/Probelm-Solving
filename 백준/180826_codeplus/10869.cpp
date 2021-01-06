#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main()
{
	int A, B;
	vector<function<int(int, int)>> d;
	//���Ϳ� �����ϴ� �Լ��� �־��
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

	//�������������Ͽ� �����纸�� �ӵ��� �������ִ�.
	//foreach�� ������
	for (auto &a : d)
	{
		cout << a(A, B) << "\n";
	}
	


	return 0;
}