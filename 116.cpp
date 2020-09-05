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
 
void init() {
	height = (int) ceil(log2((double)N));
	table.assign(N, vi(height+1, -1));
}
 
void calcSparse(int par, int S) {
	table[S][0] = par;
	for (int i = 1; i <= height; i++) {
		table[S][i] = table[table[S][i-1]][i-1];
		if (table[S][i] == -1) break;
	}
}
 
void dfs(int S) {
	for (int i = 0; i < (int) G[S].size(); i++) {
		calcSparse(S, G[S][i]);
		dfs(G[S][i]);
	}
}
 
void processQ(int x, int k) {
	for (int i = 0; i <= height; i++) {
		if (k & (1<<i)) {
			x = table[x][i];
			if (x == -1) {
				cout << "-1\n";
				return;
			}
		}
	}
	cout << x+1 << "\n";
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, x, k;
	cin >> N >> Q;
	G.assign(N, vi());
	init();
	for (int i = 1; i < N; i++) {
		cin >> x;
		G[x-1].pb(i);
	}
	dfs(0);
	while(Q--) {
		cin >> x >> k;
		processQ(x-1, k);
	}
	return 0;
}
