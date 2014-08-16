/*
GAME - DP 
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define FOR(i,n) for(int i=0;i<(int)n;i++)
#define REP(i,f,t) for(int i=f;i<=t;i++)
#define debln(a) cout<< #a <<" : " << a << endl;
#define ALL(a) a.begin(),a.end()
#define minval -99999999
using namespace std;

int dx[4] = {0,0,-1,1 };
int dy[4] = {1,-1,0,0 };

class ScoreDifference {
	public:
	
	bool path[4][4];
	int A[4][4];
	int dp[(1<<16)];
	
	bool isOn(int state,int bit) {
		return ( (state & (1<<bit)) == (1<<bit) );
	}
	
	int solve(int state) {
		
		if(state==0) return dp[state]=0;
		
		if(dp[state]!=-1) return dp[state];
		
		int cbest = minval;
		
		FOR(i,16) if(isOn(state,i)) {
			if(path[i/4][i%4]) { // there is a way out
				int sz = 0;
				int cadd[4][2];
				FOR(k,4) {
					int x(i/4+dx[k]),y(i%4+dy[k]);
					if(x>=0 && x<4 && y>=0 && y<4 && !path[x][y]) {
						path[x][y]=1;
						cadd[sz][0] = x;
						cadd[sz++][1] = y;
					}
				}
				
				int calc = solve( state - (1<<i) );
				if(calc!=minval) cbest = max(cbest, A[i/4][i%4] - calc);
				
				FOR(k,sz) {
					path[ cadd[k][0] ][ cadd[k][1] ] = 0;
				}
			}
		}
		return dp[state] = cbest;
	}
	int maximize(vector <string> board) {
		memset(dp,-1,sizeof dp);
		
		FOR(i,4) { 
			istringstream iss(board[i]);
			FOR(j,4) { iss >> A[i][j]; }
		}
//		FOR(i,4) { FOR(j,4) cout << A[i][j] << " "; cout << endl; }
		memset(path,0,sizeof path);
		FOR(i,4) { path[i][0]=1; path[0][i]=1; path[3][i]=1; path[i][3]=1; }
		
		solve( ((1<<16) - 1));
		
		return dp[(1<<16)-1];
	}
};

// Powered by PopsEdit
