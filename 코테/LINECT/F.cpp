#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;

struct pos {
    string order;
    int num;
};

struct Data {
    string order;
    int num;
};

map<int, pos> Company;
map<char, Data> people;


vector<string> solution(vector<string> companies, vector<string> applicants) {
    vector<string> answer;
    
    map<char, int>m;
    for (int i = 0; i < companies.size(); i++) {
        char company;
        string order;
        int num;
        stringstream ss(companies[i]);
        ss >> company;
        m[company] = i;
        ss >> order;
        string temp;
        ss >> temp;
        num = stoi(temp);
        Company[i] = { order,num };
    }

    for (int i = 0; i < applicants.size(); i++) {
        stringstream ss(applicants[i]);
        char person;
        string order, temp;
        ss >> person >> order >> temp;
        int num = stoi(temp);
        temp = "";
        for (int j = 0; j < num; j++) {
            temp += to_string(m[order[j]]);
        }
        order = temp;
        people[person] = {order, 0 };
    }
    
    vector<vector<char>> Com(companies.size());
    set<int> reject;

    while (!people.empty()) {
        for (auto iter = people.begin(); iter != people.end();) {
            if ((*iter).second.num == (*iter).second.order.size()) iter = people.erase(iter);
            else {
                Com[m[(*iter).first]].push_back((*iter).first);
                iter++;
            }
        }

        for (int i = 0; i < Com.size(); i++) {
            int cnt = 0;
            bool out = false;
            vector<bool> check(Com[i].size());
            for (int j = 0; j < Company[i].order.size(); j++) {
                if (out) {
                    for (int l = 0; l < Com[i].size(); l++) {
                        if (!check[l]) {
                            reject.insert(l);
                        }
                    }
                    break;
                }
                for (int k = 0; k < Com[i].size(); k++) {
                    if (Company[i].order[j] == Com[i][k] && !check[k]) {
                        cnt++;
                        check[k] = true;
                    }
                    if (cnt == Company[i].num) {
                        out = true;
                        break;
                    }
                }
            }
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
