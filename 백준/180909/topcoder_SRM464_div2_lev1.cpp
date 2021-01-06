#include <algorithm>
using namespace std;

class ColorfulBoxesAndBalls
{
public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)
	{
		int n = min(numRed, numBlue);
		int ans = INT32_MIN;

		for (int i = 0; i <= n; i++)
		{
			int sum = (numRed - i) * onlyRed + (numBlue - i) * onlyBlue + (2 * i) * bothColors;
			ans = max(sum, ans);
		}
		return ans;
	}
};