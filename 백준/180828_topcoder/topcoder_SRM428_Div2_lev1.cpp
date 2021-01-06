#include <string>
#include <algorithm>
using namespace std;

class ThePalindrome
{
public:
	int find(string s)
	{
		int ans = 0;
		reverse(s.begin(), s.end());
		string temp = s;
		reverse(s.begin(), s.end());

		for (int i = 0; i < s.length(); i++)
		{
			if (s.substr(i) == temp.substr(i))
			{
				ans = s.length() + i;
				break;
			}
		}
		return ans;
	}
	//Ã¥ ´ä¾È
	/*int find(string s)
	{
		for (int i = s.size();; i++)
		{
			bool flag = true;
			for (int j = 0; j < s.size(); j++)
			{
				if ((i - j - 1) < s.size() && s[j] != s[i - j - 1])
				{
					flag = false;
					break;
				}
			}
			if (flag)return i;
		}
	}*/

};
