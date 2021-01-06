#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> arr;
	int temp, P, index = 0;
	scanf("%d %d", &temp, &P);
	arr.push_back(temp);

	while (true)
	{
		int num = 0;
		for (int i = 1; i <= temp;) {
			num += (int)(pow((temp % 10), P));
			temp /= 10;
		}
		if (find(arr.begin(), arr.end(), num) != arr.end())
		{
			temp = num;
			break;
		}
		else
			arr.push_back(num);
		index++;
		temp = num;
	}
	
	printf("%d\n", find(arr.begin(), arr.end(), temp) - arr.begin());
	return 0;
}