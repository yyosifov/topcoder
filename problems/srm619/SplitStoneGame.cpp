#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

class SplitStoneGame {
	public:
	string winOrLose(vector <int> v) {
		bool hasOtherThanOne = false;
		FOR(i, v.size()) if(v[i] != 1) { hasOtherThanOne = true; break; }
		if(!hasOtherThanOne) return "LOSE";
		
		if(v.size() <= 2) return "LOSE";
		return v.size() & 1 ? "WIN" : "LOSE";
	}
};