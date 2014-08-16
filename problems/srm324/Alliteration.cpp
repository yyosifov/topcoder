#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>
#define FOR(i,n) for(int i=0;i<(int)n;i++)
#define debln(a) cout << #a << " : " << a << endl;
using namespace std;


class Alliteration {
	public:
	int count(vector <string> words) {
		vector<char> v;
		int lit(0);
		FOR(i,words.size()) v.push_back(tolower(words[i][0]));
		FOR(i,v.size()) {
			int h(0);
			int j = i + 1;
			while(j<v.size() && v[j]==v[i]) { h++; j++; }
			if(h) {
				i = j-1;
				lit++;
			}
		}
		return lit;
	}
};

// Powered by PopsEdit
