//2157
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] += 'a' - 'A';
    }
    for (auto iter = new_id.begin(); iter != new_id.end();) {
        if (!isdigit((*iter)) && !isalpha((*iter)) && (*iter) != '.' && (*iter) != '_' && (*iter) != '-') iter = new_id.erase(iter);
        else iter++;
    }

    for (auto iter = new_id.begin(); iter != new_id.end();) {
        if (iter == new_id.begin()) iter++;
        else {
            if ((*iter) == '.' && (*(iter - 1)) == '.') iter = new_id.erase(iter);
            else iter++;
        }
    }

    if (new_id[0] == '.') new_id.erase(new_id.begin());
    if ((*new_id.rbegin()) == '.') new_id = new_id.substr(0, new_id.size() - 1);


    if (new_id.size() == 0) new_id = "a";
    else if (new_id.size() > 15) {
        new_id = new_id.substr(0, 15);
        if (new_id[14] == '.') new_id = new_id.substr(0, 14);
    }

    if (new_id.size() <= 2) {
        char temp = new_id[new_id.size() - 1];
        while (new_id.size() < 3) new_id += temp;
    }

    answer = new_id;
    return answer;
}

void solve() {
    solution("123_.def");
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
