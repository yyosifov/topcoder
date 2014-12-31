#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

class TheKingsTree {
public:
        vector< vector<int> > v;
        vector< int > p;
        int dp[64][64][64];
    int treeSize[64];
        int n;

    int calcTreeSize(int vert) {
            if(treeSize[vert] != -1) return treeSize[vert];
            int res = 1;
            FOR(i, v[vert].size()) res += calcTreeSize(v[vert][i]);
            return treeSize[vert] = res;
    }

    int iterateChildren(int vert, int ind, int r, int g) {
        if(ind >= v[vert].size()) return 0; // end.

        int res = -1, currentVert = v[vert][ind];
        int tsz = treeSize[currentVert];
        for(int i=0;i<=tsz;i++) {
            int splitRed = i, splitGreen = tsz - i;

            if(splitRed <= r && splitGreen <= g) {
                // the configuration is possible, try it.

                int subtreeRes = solve(currentVert, splitRed, splitGreen);
                int siblingsRes = iterateChildren(vert, ind + 1, r - splitRed, g - splitGreen);
                int sum = subtreeRes + siblingsRes;
                if(res == -1) res = sum;
                res = min(res, sum);
            }
        }
            return res;
    }

    int solve(int vert, int r, int g) {
        if(dp[vert][r][g] != -1) return dp[vert][r][g];

        int res = -1;

        if(r) {
            // this vertex can be red.
            int redResult = iterateChildren(vert, 0, r-1, g);
            res = redResult + r; // children sum + r
        }

        if(g) {
            int greenResult = iterateChildren(vert, 0, r, g-1);
            if(res == -1) res = greenResult + g;
            else res = min(res, greenResult + g);
        }

        return dp[vert][r][g] = res;
    }

    void init(vector<int> & parent) {
        n = parent.size() + 1;
        p = parent;
            v.resize(n);

            FOR(i, 64) treeSize[i] = -1;
            FOR(i, 64) FOR(j, 64) FOR(k, 64) dp[i][j][k] = -1;
        FOR(i, parent.size()) v[parent[i]].push_back(i+1);
        FOR(i, n) calcTreeSize(i); // calc all treeSize[i];
    }

    int getNumber(vector <int> parent) {
        init(parent);

        int cost = -1;
        for(int i=0;i<=n;i++) {
            // divide the count of all vertixes to [R] and to [G]. Try to see what will be the cost
            int r = i, g = n - i;
            int ccost = solve(0, r, g);
            if(cost == -1) cost = ccost;
            cost = min(cost, ccost);
        }
        return cost;
    }
};

// Powered by PopsEdit
