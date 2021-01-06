#include <iostream>
using namespace std;

int main()
{
	
	//람다함수
	// auto 컴파일러가 자료형을 유추하여 정해줌
	//자료형은 <functional> 안에 있음
	auto print = [] {
		cout << "8/2" << "\n";
	};

	print();

	return 0;
}