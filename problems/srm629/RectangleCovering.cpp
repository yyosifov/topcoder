#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef pair<int, int> pii;

class RectangleCovering {
	public:
	int n;
	vector<int> bh, bw;
	int solve(int h, int w) {
		int cw = 0, count(0);
		vector<bool> used(n, 0);
		while(true) {
			int bestW(-1), bestIndex(-1);
			pii bestBoard;
			
			FOR(i, n) {
				if(used[i]) continue;
				
				if(bh[i] > h) {
					if(bestW < bw[i]) {
						bestW = bw[i];
						bestBoard = make_pair(bh[i], bw[i]);
						bestIndex = i;
					}
				}
				
				// rotate
				if(bw[i] > h) {
					if(bestW < bh[i]) {
						bestW = bh[i];
						bestBoard = make_pair(bw[i], bh[i]);
						bestIndex = i;
					}
				}
			}
			
			if(bestIndex == -1) return -1;
			
			used[bestIndex] = true;
			cw += bestBoard.second;
			count++;
			
			if(cw >= w) return count;
		}
		return -1;
	}
	int minimumNumber(int holeH, int holeW, vector <int> boardsH, vector <int> boardsW) {
		n = boardsH.size(), bh = boardsH, bw = boardsW;
		
		// solve for rotated initial board to cover.
		int r1 = solve(holeH, holeW);
		int r2 = solve(holeW, holeH);
		if(r1 == -1) return r2;
		if(r2 == -1) return r1;
		return min(r1, r2);
	}
};