/*
Kruskal style ... MST
*/
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#define FOR(i,n) for(int i=0;i<(int)n;i++)
#define debln(a) cout << #a << " : " << a << endl;
#define mp(a,b) make_pair(a,b)
#define u first
#define w second
using namespace std;

typedef pair<int,int> pii;

struct type {
	int a,b,e;
	type() {}
	type(int _a,int _b,int _e) {
		a = _a;
		b = _b;
		e = _e;
	}
};

bool cmp(type a,type b) {
	return a.e < b.e;
}

class BlockEnemy {
	public:
	vector<vector<pii> > v;
	vector<type> edges;
	vector<int> set;
	vector<int> nset;
	vector<int> div;
	vector<bool> used;
	vector<bool> ready;
	vector<type> del;
	type forbidden;
	int n;
	int m;
	
	bool eq(type f,type t) {
		return ( (f.a==t.a && f.b==t.b && f.e==t.e) || (f.a==t.b && f.b==t.a && f.e==t.e) );
	}
	bool deleted(type f) {
		FOR(i,del.size()) if(eq(f,del[i])) return true;
		return (eq(f,forbidden));
	}
	void bfs(int s,int g) {
		queue<int> q;
		q.push(s);
		used[s] = 1;
		while(!q.empty()) {
			int f = q.front();
			nset[ f ] = g;
			q.pop();
			FOR(i,v[f].size()) {
				if(!deleted(type(f,v[f][i].u,v[f][i].w)) && !used[ v[f][i].u ]) {
					used[ v[f][i].u ] = 1;
					q.push( v[f][i].u );
				}
			}
		}
	}
	bool good(type x) {
		if(set[x.a] != set[x.b]) return false;
		forbidden = x;
		used.clear();
		used.resize(n,0);
		nset.clear();
		nset.resize(n,-1);
		forbidden = x;
		int g(1);
		bool sense(false);
		FOR(i,n) if(!used[i]) {  bfs(i,g); g++;}
		FOR(i,m) for(int j=i+1;j<m;j++)
		if(set[ div[i] ] == set[ div[j] ]
		&& nset[ div[i] ] != nset[ div[j] ]) { sense=true; }
		if(sense) set = nset;
		return sense;
	}
	int minEffort(int N, vector <string> roads, vector <int> o) {
		m = o.size();
		n = N;
		v.resize(N);
		set.resize(n,0);
		div.resize(N,-1);
		FOR(i,m) div[i] = o[i];
		FOR(i,roads.size()) {
			int a,b,e;
			istringstream iss(roads[i]);
			iss >> a >> b >> e;
			v[a].push_back(mp(b,e));
			v[b].push_back(mp(a,e));
			edges.push_back(type(a,b,e));
		}
		sort(edges.begin(),edges.end(),cmp);
		int res(0);
		FOR(i,edges.size()) {
			if(good(edges[i])) {
				res += edges[i].e;
				del.push_back(edges[i]);
			}
		}
		return res;
	}
};
