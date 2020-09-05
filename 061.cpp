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
 
vvi G;
int N;
vector<bool> vis;
 
void dfs(int S) {
	vis[S] = true;
	for (int i = 0; i < (int) G[S].size(); i++) {
		if (!vis[G[S][i]]) dfs(G[S][i]);
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, a, b;
	cin >> N >> M;
	G.assign(N, vi());
	while(M--) {
		cin >> a >> b;
		a--;
		b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	vis.assign(N, false);
	int comp = 0;
	vi ser;
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			dfs(i);
			comp++;
			ser.pb(i+1);
		}
	}
	cout << (ser.size()-1) << "\n";
	for (int i = 0; i < (int) ser.size()-1; i++) cout << ser[i] << " " << ser[i+1] << "\n";
	return 0;
}
