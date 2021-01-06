//못품 보류
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	double ax, ay, bx, by, cx, cy, dx, dy;

	scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);

	double target = sqrt(pow(abs(ax - cx), 2) + pow(abs(ay - cy), 2));
	double ans = 10001;
	while (ax != bx && ay != by && cx != dx && cy != dy)
	{
		pair<double, double> midab = { (bx + ax) / 2, (by + ay) / 2 };
		pair<double, double> midcd = { (dx + cx) / 2, (dy + cy) / 2 };

		double temp = sqrt(pow(abs(midab.first - midcd.first), 2) + pow(abs(midab.second - midcd.second), 2));
		if (target > temp)
		{
			ans = min(ans, temp);
			ax = midab.first;
			ay = midab.second;
			cx = midcd.first;
			cy = midcd.second;
		}
		else
		{
			ans = min(ans, temp);
			bx = midab.first;
			by = midab.second;
			cx = midcd.first;
			cy = midcd.second;
		}
		target = temp;
	}

	printf("%lf", ans);
	return 0;
}