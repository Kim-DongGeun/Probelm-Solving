/*
	idea : 실수를 찾는 것이므로 같은 값은 찾을 수 없고 근사값만 찾을 수 있다.
		   오차범위까지 반복을 돌리면서 값을 찾는다.
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
		double h = (h1*h2) / (h1 + h2); //비례식을 세우면 나오는 값

		if (h > c) low = mid;
		else high = mid;
	}

	printf("%.3lf\n", low);
	return 0;
}