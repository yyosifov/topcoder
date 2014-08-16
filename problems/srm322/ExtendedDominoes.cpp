#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>
#define FOR(i,n) for(int i=0;i<(int)n;i++)
#define debln(a) cout << #a << " : " << a << endl;
using namespace std;


class ExtendedDominoes {
	public:
	int dp[64];	
	int f(int cx) {
		if(dp[cx]!=-1) return dp[cx];
		return dp[cx] = (cx-1)*f(cx-2);
	}
	long long countCycles(vector <string> p) {
		memset(dp,-1,sizeof dp);
		dp[0] = 1;
		dp[1] = 0;
		int digits[12];
		memset(digits,0,sizeof digits);
		FOR(i,p.size()) {
			digits[p[i][0]-'0']++;
			digits[p[i][1]-'0']++;
		}
		long long res(1);
		FOR(i,10) res *= f(digits[i]);
		return res;
	}
};
