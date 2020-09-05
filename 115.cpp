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
vl sumRoot, parent, subT, paths;
 
ll dfs(int S, int par) {
	if (sumRoot[S] != -1) return sumRoot[S];
	ll ans = 0;
	subT[S] = 1;
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (v != par) {
			dfs(v, S);
			ans += sumRoot[v] + subT[v];
			subT[S] += subT[v];
		}
	}
	parent[S] = par;
	return sumRoot[S] = ans;
}
 
void calcP(int S) {
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (paths[v] != -1) continue;
		paths[v] = paths[S] + N - 2*subT[v];
		calcP(v);
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	G.assign(N, vi());
	sumRoot = subT = parent = paths = vl(N, -1);
	int a, b;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);
	}
	dfs(0, -1);
	paths[0] = sumRoot[0];
	calcP(0);
	cout << paths[0];
	for (int i = 1; i < N; i++) cout << " " << paths[i];
	cout << "\n";
	return 0;
}
