#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct XY
{
	int kor;
	int eng;
	int math;
	string name;
};

bool compare(XY a, XY b)
{
	if (a.kor > b.kor)
		return true;
	else if (a.kor == b.kor) 
	{
		if (a.eng == b.eng)
		{
			if (a.math == b.math)
				return a.name.compare(b.name) < 0;

			return a.math > b.math;
		}
		return a.eng < b.eng;
	}
	else
		return false;
}

int main()
{
	int N;
	cin >> N;

	XY* xy = new XY[N];

	for (int i = 0; i < N; i++) 
		cin >> xy[i].name >> xy[i].kor >> xy[i].eng >> xy[i].math;

	sort(xy, xy + N, compare);

	for (int i = 0; i < N; i++)
		printf("%s\n", xy[i].name.c_str());

	return 0;
}