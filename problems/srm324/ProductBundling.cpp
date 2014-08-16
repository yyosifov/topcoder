#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>
#define FOR(i,n) for(int i=0;i<(int)n;i++)
#define debln(a) cout << #a << " : " << a << endl;
using namespace std;


class ProductBundling {
	public:
	bool A[64][64];
	bool used[64];
	int n,m;
	bool can(vector<string> data,int x,int y) {
		FOR(i,n) {
			if(data[i][x]!=data[i][y]) return false;
		}
		return true;
	}
	void dfs(int vert) {
		used[vert] = 1;
		FOR(i,m) if(A[vert][i] && !used[i]) dfs(i);
	}
	int howManyBundles(vector <string> data) {
		n = data.size();
		m = data[0].size();
		memset(A,0,sizeof A);
		FOR(i,m) {
			FOR(j,m) if(can(data,i,j)) A[i][j] = A[j][i] = 1;
		}
		int res(0);
		memset(used,0,sizeof used);
		FOR(i,m) if(!used[i]) { dfs(i); res++; }
		return res;
	}
};

// Powered by PopsEdit
