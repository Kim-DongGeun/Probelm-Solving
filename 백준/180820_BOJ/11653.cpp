#include <iostream>
using namespace std;

int main() 
{
	int N;
	int A = 2;
	cin >> N;
	
	while (N != 1) //���μ�����
	{
		if (N % A == 0)
		{
			printf("%d\n", A);
			N /= A;
		}
		else
			A++;
	}
	return 0;
}