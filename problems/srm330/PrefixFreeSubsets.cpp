#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>
#define FOR(i,n) for(int i=0;i<(int)n;i++)
#define debln(a) cout << #a << " : " << a << endl;
using namespace std;


class PrefixFreeSubsets {
	public:
	bool p(string a,string b) {
		if(a.size() >= b.size()) return false;
		FOR(i,a.size()) if(a[i] != b[i]) return false;
		return true;
	}
	long long cantPrefFreeSubsets(vector <string> w) {
		sort(w.begin(),w.end());
		int n = w.size();
		vector<long long> dp(n+1,0);
		dp[n] = n;
		for(int i=n-1;i>=0;i--) {
			int j = i + 1;
			while(j<n && p(w[i],w[j])) j++;
			dp[i] = dp[i+1] + dp[j];
		}
		return dp[0];
	}
};
