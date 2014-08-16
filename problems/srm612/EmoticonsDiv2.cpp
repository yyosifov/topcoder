#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#define debln(a) cout << #a << " : " << a << endl;
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

class EmoticonsDiv2 {
	public:
	int dp[1024][1024];
	int printSmiles(int smiles) {
		int cmax = 1024 * 1024 * 1024;
		FOR(i, 1024) FOR(j, 1024) dp[i][j] = cmax;
		dp[1][1] = 1;
		for(int i=1;i<=smiles;i++) {
			for(int j=1;j<=i;j++) {
				// paste
				dp[i][j] = min(dp[i][j], dp[i-j][j] + 1);
				
				// copy
				if(i == j * 2)
				{
					for(int k=1;k<=j;k++)
					{
						dp[i][j] = min(dp[i][j], dp[i/2][k] + 2);
					}
				}
			}
		}
		
		int res = cmax;
		for(int i=1;i<=smiles;i++) { 
			res = min(res, dp[smiles][i]); 
			//cout << dp[smiles][i] << " "; 
		}
		return res;
	}
};