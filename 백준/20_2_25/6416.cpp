#pragma warning (disable : 4996)
#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main() {
	int u, v;
	for(int T = 1; ; T++) {
		s.clear();
		int lines = 0;
		while(true) {
            scanf("%d %d", &u, &v);
            if ((u + v) < 0) return 0;
			else if (!(u + v)) {
				if (lines == 0 || (lines + 1) == (int)s.size())
					printf("Case %d is a tree.\n", T);
				else
					printf("Case %d is not a tree.\n", T);
				break;
			}
			s.insert(u);
			s.insert(v);
			lines++;
		}
	}
	return 0;
}

