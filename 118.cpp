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
 
int N, height;
vvi G, table;
vi depth;
 
void init() {
	height = (int) ceil(log2((double) N));
	table.assign(N, vi(height+1, -1));
	depth.assign(N, 0);
	G.assign(N, vi());
}
 
void calcSparse(int S, int par) {
	table[S][0] = par;
	for (int i = 1; i <= height; i++) {
		table[S][i] = table[table[S][i-1]][i-1];
		if (table[S][i] == -1) break;
	}
}
 
void dfs(int S, int par) {
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (v == par) continue;
		depth[v] = depth[S]+1;
		calcSparse(v, S);
		dfs(v, S);
	}
}
 
int LCA(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	for (int i = height; i >= 0; i--) {
		if (depth[b] - (1<<i) >= depth[a])
			b = table[b][i];
	}
	if (a == b) return a;
	for (int i = height; i >= 0; i--) {
		if (table[a][i] != table[b][i]) {
			a = table[a][i];
			b = table[b][i];
		}
	}
	return table[a][0];
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, a, b, l;
	cin >> N >> Q;
	init();
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);
	}
	dfs(0, -1);
	while(Q--) {
		cin >> a >> b;
		a--;
		b--;
		l = LCA(a, b);
		cout << depth[a]+depth[b]-2*depth[l] << "\n";
	}
	return 0;
}
