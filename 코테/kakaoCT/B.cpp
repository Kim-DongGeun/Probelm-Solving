#include <string>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

vector<string> Split(string order, int count) {
    vector<string> temp;
    if (order.size() < count) return temp;
    sort(order.begin(), order.end());
    vector<bool> permutation(order.length());
    for (int i = 0; i < count; i++) {
        permutation[permutation.size() - 1 - i] = 1;
    }

    do {
        string x = "";
        for (int i = 0; i < permutation.size(); i++) {
            if (permutation[i]) x += order[i];
        }
        temp.push_back(x);
    } while (next_permutation(permutation.begin(), permutation.end()));

    return temp;
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());

    for (int i = 0; i < course.size(); i++) {
        vector<vector<string>> splitOrders;
        int MAX = 0;
        set<string> maxOrders;
        for (int j = 0; j < orders.size(); j++) {
            vector<string> temp = Split(orders[j], course[i]);
            splitOrders.push_back(temp);
        }

        for (int j = 0; j < splitOrders.size(); j++) {
            for (int k = 0; k < splitOrders[j].size(); k++) {
                int cnt = 0;
                string com = splitOrders[j][k];
                for (int l = 0; l < splitOrders.size(); l++) {
                    if (find(splitOrders[l].begin(), splitOrders[l].end(), com) != splitOrders[l].end())
                        cnt++;
                }
                if (cnt >= 2 && cnt > MAX) {
                    MAX = cnt;
                    maxOrders.clear();
                    maxOrders.insert(com);
                }
                else if (cnt == MAX) maxOrders.insert(com);
            }
        }

        for (auto x : maxOrders)
            answer.push_back(x);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

void solve() {
    solution({ "XYZ", "XWY", "WXA" }, { 2,3,4 });
}

int main() {
    //cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}