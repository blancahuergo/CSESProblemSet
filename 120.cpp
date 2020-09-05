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
vvi G;
vi subT, pos, arr;
vl bit, values;
 
void dfs(int S, int par) {
	pos[S] = (int) arr.size();
	arr.pb(S);
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (v == par) continue;
		dfs(v, S);
		subT[S] += subT[v]+1;
	}
}
 
void add(int x, int val) {
	while(x < N) {
		bit[x] += val;
		x = x | (x+1);
	}
}
 
ll sum(int r) {
	ll ret = 0ll;
	while (r >= 0) {
		ret += bit[r];
		r = (r & (r+1))-1;
	}
	return ret;
}
 
ll sumRange(int l, int r) {
	ll ans = sum(r);
	if (l) ans -= sum(l-1);
	return ans;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, a, b, c;
	cin >> N >> M;
	G.assign(N, vi());
	subT.assign(N, 0);
	bit.assign(N, 0ll);
	pos.assign(N, 0);
	values = vl(N);
	for (int i = 0; i < N; i++) cin >> values[i];
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);
	}
	dfs(0, -1);
	for (int i = 0; i < N; i++) add(pos[i], values[i]);
	while(M--) {
		cin >> c;
		if (c == 1) {
			cin >> a >> b;
			a--;
			add(pos[a], b - values[a]);
			values[a] = b;
		} else {
			cin >> a;
			a--;
			cout << sumRange(pos[a], pos[a] + subT[a]) << "\n";
		}
	}
	return 0;
}
