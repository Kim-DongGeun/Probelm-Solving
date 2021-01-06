#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int input, arr[1000001];

	cin >> input;
	
	arr[1] = 0; // �ʱ����� 1�϶��� �ּڰ� 0

	for (int i = 2; i <= input; i++)
	{
		arr[i] = arr[i - 1] + 1; //�켱 1�� ����� ���� 1�� ���Ѱ��� �־�д�
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1); //3���� �������� �� 1�� �� ���� ���ؼ� �� ���� ���� ����
		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1); //2�� �������� �� 1�� �� ���� ���ؼ� �� ���� ���� ����
	}

	cout << arr[input] << "\n";

	return 0;
}