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
typedef pair<int, pii> triple;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<string> vs;
#define fir first
#define sec second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()

vl dist;
int N;
vector<triple> E;
vvi G;
vi dp;
vector<bool> vis;

bool reachCyc(int u) {
	return dist[u] != 1e18;
}

bool reachEnd(int u) {
	vis[u] = true;
	if (dp[u] != -1) return dp[u];
	for (auto v: G[u]) {
		if (!vis[v] && reachEnd(v)) {
			dp[u] = 1;
			return true;
		}
	}
	dp[u] = 0;
	return false;
}

void solve() {
	dist.assign(N, 1e18);
	dist[0] = 0;
	int u, v, c;
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < (int) E.size(); j++) {
			u = E[j].second.first;
			v = E[j].second.second;
			c = E[j].first;
			dist[v] = min(dist[v], dist[u]+c);
		}
	}
	vi cyc;
	for (int j = 0; j < (int) E.size(); j++) {
		u = E[j].second.first;
		v = E[j].second.second;
		c = E[j].first;
		if (dist[v] > dist[u]+c) {
			dist[v] = dist[u]+c;
			cyc.push_back(v);
		}
	}
	if (dist[N-1] == 1e18) cout << "-1\n";
	else if (cyc.empty()) cout << -dist[N-1];
	else {
		dp.assign(N, -1);
		dp[N-1] = 1;
		for (int i = 0; i < (int) cyc.size(); i++) {
			u = cyc[i];
			if (reachCyc(u)) {
				vis.assign(N, false);
				if (!reachEnd(u)) continue;
				cout << "-1";
				return;
			}
		}
		cout << -dist[N-1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, a, b, c;
	cin >> N >> M;
	E.assign(M, triple());
	G.assign(N, vi());
	while(M--) {
		cin >> a >> b >> c;
		a--;
		b--;
		E.pb(mp(-c, mp(a, b)));
		G[a].pb(b);
	}
	solve();
	return 0;
}
