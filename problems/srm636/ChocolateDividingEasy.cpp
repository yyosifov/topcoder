#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

class ChocolateDividingEasy {
	public:
	int sum[(1<<6)][(1<<6)];
	int n, m;
	
	int getSum(int fx, int fy, int ex, int ey) {
		// from [fx,fy] to [ex,ey]11[ex,ey] = " << sum[ex][ey] << endl;
		int res = sum[ex][ey];
		if(fx-1>=0 && fy-1>=0) res += sum[fx-1][fy-1];		
		if(fx-1>=0) res -= sum[fx-1][ey];
		if(fy-1>=0) res -= sum[ex][fy-1];
		return res;
	}
	int findBest(vector <string> chocolate) {
		n = chocolate.size(), m = chocolate[0].size();
		FOR(i, n) FOR(j, m) {
			int csum = chocolate[i][j] - '0';
			if(i-1>=0) csum += sum[i-1][j];
			if(j-1>=0) csum += sum[i][j-1];
			if(i-1 >= 0 && j-1>=0) csum -= sum[i-1][j-1];
			sum[i][j] = csum;
		}
		
		int best = -1;
		for(int i=1;i<n-1;i++) {
			for(int j=i+1;j<n;j++) {
				// cut horizontally at I and at J
				for(int k=1;k<m-1;k++) {
					for(int f=k+1;f<m;f++) {
						// cut vertically at F and at K
						int cbest = getSum(0,0,i-1,k-1);
						cbest = min(cbest, getSum(0, k, i-1, f-1));
						cbest = min(cbest, getSum(0, f, i-1, m-1));

						cbest = min(cbest, getSum(i, 0, j-1, k-1));
						cbest = min(cbest, getSum(i, k, j-1, f-1));
						cbest = min(cbest, getSum(i, f, j-1, m-1));
						
						cbest = min(cbest, getSum(j, 0, n-1, k-1));
						cbest = min(cbest, getSum(j, k, n-1, f-1));
						cbest = min(cbest, getSum(j, f, n-1, m-1));
						
						best = max(best, cbest);
					}
				}
			}
		}
		return best;
	}
};
