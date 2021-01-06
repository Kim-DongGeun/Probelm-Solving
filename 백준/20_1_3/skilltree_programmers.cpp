#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++) {
		vector<bool> check(skill.size(), false);
		bool ansCheck = true;
		for (int j = 0; j < skill_trees[i].length(); j++) {
			if (skill.find(skill_trees[i][j]) == 0) {
				check[skill.find(skill_trees[i][j])] = true;
			}
			else if (skill.find(skill_trees[i][j]) != string::npos) {
				if (check[skill.find(skill_trees[i][j]) - 1]) {
					check[skill.find(skill_trees[i][j])] = true;
				}
				else {
					ansCheck = false;
					break;
				}
			}
		}
		if (ansCheck)
			answer++;
	}

	return answer;
}

int main() {
	vector<string> k = { "BACDE", "CBADF", "AECB", "BDA" };
	solution("CBD", k);
	return 0;
}