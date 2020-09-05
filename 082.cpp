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
 
int N, A, B;
vvi G, Grev;
vector<bool> vis, visRev;
 
void dfs(int S) {
	vis[S] = true;
	A++;
	for (int i = 0; i < (int) G[S].size(); i++) {
		if (!vis[G[S][i]]) dfs(G[S][i]);
	}
}
 
void dfsRev(int S) {
	visRev[S] = true;
	B++;
	for (int i = 0; i < (int) Grev[S].size(); i++) {
		if (!visRev[Grev[S][i]]) dfsRev(Grev[S][i]);
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, a, b;
	cin >> N >> M;
	G.assign(N, vi());
	Grev.assign(N, vi());
	while(M--) {
		cin >> a >> b;
		a--;
		b--;
		G[a].pb(b);
		Grev[b].pb(a);
	}
	if (N == 1) cout << "YES\n";
	else {
		vis.assign(N, 0);
		dfs(0);
		if (A != N) {
			cout << "NO\n";
			for (int i = 1; i < N; i++) {
				if (!vis[i]) {
					cout << "1 " << i+1 << "\n";
					return 0;
				}
			}
		}
		visRev.assign(N, 0);
		dfsRev(0);
		if (B != N) {
			cout << "NO\n";
			for (int i = 1; i < N; i++) {
				if (!visRev[i]) {
					cout << i+1 << " 1\n";
					break;
				}
			}
		} else cout << "YES\n";
	}
	return 0;
}
