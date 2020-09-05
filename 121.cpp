#include <iostream>
#include <fstream>
#include <cfloat>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <climits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<string> vs;
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()
 
int N;
vvi G, HLD;
vl val;
vi depth, subT, par;
vpii chainBelong;
vvl BIT;
 
void dfs(int S, int p) {
	int ans = 0;
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (v == p) continue;
		depth[v] = depth[S]+1;
		par[v] = S;
		dfs(v, S);
		ans += subT[v];
	}
	subT[S] = ans+1;
}
 
void decompose(int node, int chain) {
	HLD[chain].pb(node);
	chainBelong[node] = mp(chain, (int) HLD[chain].size()-1);
	int sz = -1, ch = -1;
	for (int i = 0; i < (int) G[node].size(); i++) {
		int v = G[node][i];
		if (depth[v] < depth[node]) continue;
		if (subT[v] > sz) {
			sz = subT[v];
			ch = v;
		}
	}
	if (sz == -1) return;
	decompose(ch, chain);
	for (int i = 0; i < (int) G[node].size(); i++) {
		int v = G[node][i];
		if (depth[v] < depth[node] || v == ch) continue;
		HLD.pb(vi());
		decompose(v, HLD.size()-1);
	}
}
 
void add(int ch, int pos, ll num) {
	while(pos < (int) BIT[ch].size()) {
		BIT[ch][pos] += num;
		pos = pos | (pos+1);
	}
}
 
void makeBITs() {
	for (int i = 0; i < (int) HLD.size(); i++) {
		BIT.pb(vl(HLD[i].size(), 0));
		for (int j = 0; j < (int) HLD[i].size(); j++) {
			add(i, j, val[HLD[i][j]]);
		}
	}
}
 
ll calcPath(int ch, int pos) {
	ll ret = 0ll;
	pii curP;
	int p;
	while(ch >= 0) {
		while(pos >= 0) {
			ret += BIT[ch][pos];
			pos = (pos & (pos+1))-1;
		}
		p = par[HLD[ch][0]];
		if (p == -1) break;
		curP = chainBelong[p];
		ch = curP.first;
		pos = curP.second;
	}
	return ret;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, c, a, b;
	ll num;
	cin >> N >> Q;
	G.assign(N, vi());
	depth.assign(N, 0);
	val = vl(N);
	subT.assign(N, 0);
	par.assign(N, -1);
	for (int i = 0; i < N; i++) cin >> val[i];
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		a--;
		b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(0, -1);
	chainBelong.assign(N, pii());
	HLD = vvi(1, vi());
	decompose(0, 0);
	makeBITs();
	while(Q--) {
		cin >> c;
		if (c == 2) {
			cin >> a;
			a--;
			cout << calcPath(chainBelong[a].first, chainBelong[a].second) << "\n";
		} else {
			cin >> a >> num;
			a--;
			add(chainBelong[a].first, chainBelong[a].second, num - val[a]);
			val[a] = num;
		}
	}
	return 0;
}
