#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class KiwiJuiceEasy
{
public:
	vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId)
	{
		for (int i = 0; i < fromId.size(); i++)
		{
			//tech 1
			//int vol = min(bottles[fromId[i]], capacities[i] - bottles[toId[i]]);

			//bottles[fromId[i]] -= vol;
			//bottles[toId[i]] += vol;

			//tech2 
			int sum = bottles[fromId[i]] + bottles[toId[i]];
			bottles[toId[i]] = min(capacities[i],sum);
			bottles[fromId[i]] = sum - bottles[toId[i]];
		}
		return bottles;
	}
};


int main()
{
	return 0;
}