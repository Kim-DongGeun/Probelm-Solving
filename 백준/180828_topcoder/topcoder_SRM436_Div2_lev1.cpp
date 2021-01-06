#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FriendScore {
public:
	int highestScore(vector<string> friends)
	{
		int n = friends.size();
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					continue;
				
				if (friends[i][j] == 'Y')
					sum++;
				else
				{
					for (int k = 0; k < n; k++)
					{
						//공통 친구가 있는지 탐색
						if (friends[j][k] == 'Y' && friends[k][i] == 'Y')
						{
							sum++;
							break;
						}
					}
				}
			}
			ans = max(ans, sum);
		}
		return ans;
	}
};
