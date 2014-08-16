#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>
#define FOR(i,n) for(int i=0;i<(int)n;i++)
#define debln(a) cout << #a << " : " << a << endl;
using namespace std;


class PalindromeDecoding {
	public:
	string decode(string code, vector <int> p, vector <int> l) {
		string res = code;
		FOR(i,p.size()) {
			string s = res.substr(p[i],l[i]);
			string cres = "";
			FOR(j,p[i]) cres += res[j];
			cres += s;
			reverse(s.begin(),s.end());
			cres += s;
			for(int j=p[i]+l[i];j<res.size();j++) cres += res[j];
			res = cres;
		}
		return res;
	}
};

// Powered by PopsEdit
