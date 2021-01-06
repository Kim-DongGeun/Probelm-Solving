#include <iostream>
#include <functional>
using namespace std;

int main()
{
	int n;
	cin >> n;

	//재귀함수를 사용하기 위해서 캡쳐에 &를 넣어서 함수 f를 사용하였다.
	function<int(int)> f = [&](int n) {
		if (n <= 1)return n;
		else return f(n - 1) + f(n - 2);
	};

	cout << f(n) << "\n";
	return 0;
}