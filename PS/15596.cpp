#include <vector>
using namespace std;


long long sum(std::vector<int>& a) {
	long long n = 0;
	for (int i = 0; i < a.size(); i++) n += (long long)a[i];
	return n;
}