#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<int> s;
	for (int i = heights.size() - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (heights[i] < heights[j]) {
				s.push(j + 1);
				break;
			}
			else if (j == 0)
				s.push(0);
		}
	}
	answer.push_back(0);
	while(!s.empty()){
		answer.push_back(s.top());
		s.pop();
	}

	return answer;
}