//2157
#include <string>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

vector<int> solution(vector<int> ball, vector<int> order) {
    vector<int> answer;

    deque<int> q;
    for (int x : ball) q.push_back(x);

    vector<int> stay;
    for (int i = 0; i < order.size(); i++) {
        if (*q.begin() == order[i] || *q.rbegin() == order[i]) {
            if (!stay.empty()) {

                while (true) {
                    bool out = false;
                    for (auto iter = stay.begin(); iter != stay.end();) {
                        if (*iter == *q.begin()) {
                            answer.push_back(*iter);
                            iter = stay.erase(iter);
                            q.pop_front();
                            out = true;
                        }
                        else if (*iter == *q.rbegin()) {
                            answer.push_back(*iter);
                            iter = stay.erase(iter);
                            q.pop_back();
                            out = true;
                        }
                        else iter++;
                    }
                    if (!out) break;
                }
            }
            if (*q.begin() == order[i]) {
                answer.push_back(order[i]);
                q.pop_front();
            }
            else {
                answer.push_back(order[i]);
                q.pop_back();
            }
        }
        else {
            stay.push_back(order[i]);
        }
    }

    return answer;
}

void solve() {
    solution({ 11,2,9,13,24 }, { 9,2,13,24,11 });
}

int main() {
    //cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
