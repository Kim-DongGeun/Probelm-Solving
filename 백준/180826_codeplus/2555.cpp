#include <iostream>
using namespace std;

int main()
{
	
	//�����Լ�
	// auto �����Ϸ��� �ڷ����� �����Ͽ� ������
	//�ڷ����� <functional> �ȿ� ����
	auto print = [] {
		cout << "8/2" << "\n";
	};

	print();

	return 0;
}