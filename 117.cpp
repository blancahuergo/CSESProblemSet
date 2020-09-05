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
	G.assign(N, vi());
	depth.assign(N, 0);
}
 
void calcSparse(int S, int par) {
	table[S][0] = par;
	for (int i = 1; i <= height; i++) {
		table[S][i] = table[table[S][i-1]][i-1];
		if (table[S][i] == -1) break;
	}
}
 
void dfs(int S) {
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		calcSparse(v, S);
		depth[v] = depth[S]+1;
		dfs(v);
	}
}
 
void LCA(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	for (int i = height; i >= 0; i--) {
		if (depth[b] - (1<<i) >= depth[a])
			b = table[b][i];
	}
	if (a == b) {
		cout << a+1 << "\n";
		return;
	}
	for (int i = height; i >= 0; i--) {
		if (table[a][i] != table[b][i]) {
			a = table[a][i];
			b = table[b][i];
		}
	}
	cout << table[a][0]+1 << "\n";
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, a, b;
	cin >> N >> Q;
	init();
	for (int i = 1; i < N; i++) {
		cin >> a;
		G[a-1].pb(i);
	}
	dfs(0);
	while(Q--) {
		cin >> a >> b;
		LCA(a-1, b-1);
	}
	return 0;
}
