#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define FOR(i,n) for(int i=0;i<n;i++)
#define maxval 1000000000L
typedef long double ld;
using namespace std;

class CandyMaking {
	public:
	int n;
	vector<int> c, d;
	ld calc(ld val) {
		ld res(0);
		FOR(i, n) {
			ld cd = c[i] * val;
			res += abs(cd - d[i]);
		}
		return res;
	}
	
	double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight) {
		c = containerVolume, d = desiredWeight, n = c.size();
		ld minRatio(-1), maxRatio(-1), minTotal(-1), maxTotal(-1);
		FOR(i, n) {
			ld ratio = (ld)d[i] / (ld)c[i];
			ld cc = calc(ratio);
			if(i == 0) { minRatio = maxRatio = ratio; minTotal = maxTotal = cc; }
			if(minTotal > cc) { minTotal = cc, minRatio = ratio; }
			if(maxTotal < cc) { maxTotal = cc, maxRatio = ratio; }
		}
		
		ld l( min(minRatio, maxRatio) ), r( max(minRatio, maxRatio) );
		for(int i=0;i<200;i++) {
			ld mid = (l+r) / 2, sl = calc(l), sr = calc(r);
			if(sl < sr) { r = mid; }
			else l = mid;
		}
		
		ld cmid = (l+r) / 2;
		ld res = calc(cmid);
		return res;
	}
};