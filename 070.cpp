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

int N, M;
vector<triple> E;
vl dist;

void solve() {
	dist.assign(N, 1e18);
	dist[0] = 0;
	int u, v, c;
	vi pre = vi(N, -1);
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < M; j++) {
			u = E[j].second.first;
			v = E[j].second.second;
			c = E[j].first;
			if (dist[v] > dist[u]+c) {
				pre[v] = u;
				dist[v] = dist[u]+c;
			}
		}
	}
	int beg = -1;
	for (int j = 0; j < M; j++) {
		u = E[j].second.first;
		v = E[j].second.second;
		c = E[j].first;
		if (dist[v] > dist[u]+c) {
			pre[v] = u;
			dist[v] = dist[u]+c;
			beg = v;
		}
	}
	if (beg == -1) {
		cout << "NO\n";
		return;
	} else {
		for (int i = 0; i < N; i++) beg = pre[beg];
		vi cyc;
		u = beg;
		while(true) {
			cyc.pb(u);
			if (u == beg && (int) cyc.size() > 1) break;
			u = pre[u];
		}
		reverse(cyc.begin(), cyc.end());
		cout << "YES\n" << cyc[0]+1;
		for (int i = 1; i < (int) cyc.size(); i++) {
			cout << " " << cyc[i]+1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> N >> M;
	E.assign(M, triple());
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		E[i] = mp(c, mp(a, b));
	}
	solve();
	return 0;
}
