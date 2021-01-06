/*
	idea : �Ǽ��� ã�� ���̹Ƿ� ���� ���� ã�� �� ���� �ٻ簪�� ã�� �� �ִ�.
		   ������������ �ݺ��� �����鼭 ���� ã�´�.
*/
#include <iostream>
#include <math.h>
using namespace std;

double x, y, c;

int main()
{
	scanf("%lf %lf %lf", &x, &y, &c);

	double low = 0;
	double high = x < y ? x : y;

	while (abs(high - low) > 1e-6)
	{
		double mid = (low + high) / 2.0;
		double d = mid;
		double h1 = sqrt((x*x) - (d*d));
		double h2 = sqrt((y*y) - (d*d));
		double h = (h1*h2) / (h1 + h2); //��ʽ��� ����� ������ ��

		if (h > c) low = mid;
		else high = mid;
	}

	printf("%.3lf\n", low);
	return 0;
}