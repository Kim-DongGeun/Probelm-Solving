#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;

    int n = cards.size();
    for (int i = 0; i < n; i++)
        if (cards[i] > 10) cards[i] = 10;

    int player = 0, dealer = 0;
    int i = 0;
    while (i < n) {
        player = 0;
        dealer = 0;
        if (cards[i] == 1 && player + cards[i] + 10 <= 21) {
            player += 11;
            i++;
        }
        else player += cards[i++];
        if (i == n) break;
        if (cards[i] == 1 && dealer + cards[i] + 10 <= 21) {
            dealer += 11;
            i++;
        }
        else dealer += cards[i++];
        if (i == n) break;
        if (cards[i] == 1 && player + cards[i] + 10 <= 21) {
            player += 11;
            i++;
        }
        else player += cards[i++];

        if (i == n) break;
        int temp;
        if (cards[i] == 1 && dealer + cards[i] + 10 <= 21) {
            dealer += 11;
            i++;
            temp = 1;
        }
        else {
            temp = cards[i];
            dealer += cards[i++];
        }

        if (dealer == player && player == 21) continue;
        else if (player == 21) {
            answer += 3;
            continue;
        }
        else if (dealer == 21 || player > 21) {
            answer -= 2;
            continue;
        }
        else if (dealer > 21) {
            answer += 2;
            continue;
        }
        if (temp == 1 || temp >= 7) {
            int out = 0;
            while (i < n && player < 17) {
                if (cards[i] == 1 && player + cards[i] + 10 <= 21) {
                    player += 11;
                    i++;
                }
                else player += cards[i++];
                if (player == 21) {
                    out = 2;
                    break;
                }
                else if (player > 21) {
                    out = 1;
                    break;
                }
            }
            if (out == 1) continue;
            else if (out == 2) {
                answer += 3;
                continue;
            }
            else if (player < 17 && i >= n) break;
        }
        else if (temp == 2 || temp == 3) {
            int out = 0;
            while (i < n && player < 12) {
                if (cards[i] == 1 && player + cards[i] + 10 <= 21) {
                    player += 11;
                    i++;
                }
                else player += cards[i++];
                if (player == 21) {
                    out = 2;
                    break;
                }
                else if (player > 21) {
                    out = 1;
                    break;
                }
            }
            if (out == 1) continue;
            else if (out == 2) {
                answer += 3;
                continue;
            }
            else if (player < 12 && i >= n) break;
        }
        // µô·¯ ¹ÞÀ» Â÷·Ê
        bool OUT = false;
        while (i < n && dealer < 17) {
            if (cards[i] == 1 && dealer + cards[i] + 10 <= 21) {
                dealer += 11;
                i++;
            }
            else dealer += cards[i++];
            if (dealer > 21) {
                OUT = true;
                break;
            }
        }
        if (i >= n && dealer < 17) break;
        if (OUT) {
            answer += 2;
            continue;
        }
        answer += (player < dealer) ? -2 : 2;
    }

    return answer;
}