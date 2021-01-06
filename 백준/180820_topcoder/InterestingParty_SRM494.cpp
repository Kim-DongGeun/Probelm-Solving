#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class InterstingParty
{
public:
	int bestInvitation(vector<string> first, vector<string> second)
	{
		//map을 이용한 tech2
		map<string, int> dic; //파이썬의 딕셔너리와 유사함

		int answer = 0;
		for (int i = 0; i < first.size(); i++)
		{
			//tech 1
			/*int f = 0, s = 0;
			for (int j = 0; j < first.size(); j++)
			{
				if (first[i] == first[j]) f++;
				if (first[i] == second[j]) f++;
				if (second[i] == first[j]) s++;
				if (second[i] == second[j]) s++;
			}

			answer = max(answer, f, s);*/

			dic[first[i]] = 0; //key값을 0으로 초기화
			dic[second[i]] = 0;
		}
		for (int i = 0; i < first.size(); i++)
		{
			dic[first[i]]++; //
			dic[second[i]]++;
		}

		map<string, int>::iterator it; //iterator 생성

		for (it = dic.begin(); it != dic.end(); it++)
		{
			answer = max(answer, it->second); //iterator->first == key , iterator->second == value
		}

		return answer;
	}
};


int main()
{
	InterstingParty IP;
	vector<string> a, b;
	a.push_back("a");
	a.push_back("b");
	a.push_back("c");
	a.push_back("d");
	a.push_back("e");
	a.push_back("f");
	a.push_back("g");
	a.push_back("h");

	b.push_back("A");
	b.push_back("B");
	b.push_back("C");
	b.push_back("D");
	b.push_back("E");
	b.push_back("F");
	b.push_back("G");
	b.push_back("H");
	IP.bestInvitation(a, b);
	return 0;
}