#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

class TaroFriends {
	public:
	int calc(vector<int> c, int X, int l) {
		int ind = 0;
		sort(c.begin(), c.end());
		for(;ind<l;ind++) c[ind] += X;
		for(;ind<c.size();ind++) c[ind] -= X;
		sort(c.begin(), c.end());
		return abs(c[c.size() - 1] - c[0]);
	}
	
	int getNumber(vector <int> c, int X) {
		int best = calc(c, X, 0);
		FOR(i, c.size()) best = min(best, calc(c,X,i));
		return best;
	}
};