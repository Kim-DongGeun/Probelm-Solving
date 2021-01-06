#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
vector<int>ans;

class BatchSystem
{
public:
	vector<int> schedule(vector<int> duration, vector<string> user)
	{
		int N = duration.size();
		map<string, long long> sum;
		for (int i = 0; i < N; i++) sum[user[i]] += duration[i]; //사용자 작업시간 합 구하기

		vector<pair<string, long long>> arr;
		for (auto it = sum.begin(); it != sum.end(); it++)
			arr.push_back({ (*it).first, (*it).second });

		sort(arr.begin(), arr.end(), [](pair<string, long long> a, pair<string, long long> b)
		{
			return a.second < b.second;
		});
		vector<bool> done(N, false);

		while (ans.size() < N)
		{
			for (auto x : arr)
			{
				for (int i = 0; i < N; i++)
				{
					if (x.first == user[i] && done[i] == false)
					{
						done[i] = true;
						ans.push_back(i);
					}
				}
			}
		}

		return ans;
	}
};

int main()
{
	BatchSystem bs;
	vector<string> a = { "D", "S", "S", "M" };
	vector<int> b = { 400,100,100,100 };
	bs.schedule(b, a);

	return 0;
}