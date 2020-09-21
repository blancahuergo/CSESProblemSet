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

int N, vert;
vvi G;
vi st;
vector<bool> visited;

bool dfs(int u, int par) {
	visited[u] = true;
	st.push_back(u);
	for (auto v: G[u]) {
		if (!visited[v]) {
			if (dfs(v, u)) return true;
		} else if (v != par) {
			vert = v;
			return true;
		}
	}
	st.pop_back();
	return false;
}

void solve() {
	visited.assign(N, false);
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			if (dfs(i, -1)) {
				int j;
				for (j = 0; j < (int) st.size(); j++) {
					if (st[j] == vert) break;
				}
				cout << st.size() - j + 1 << "\n";
				cout << st[j]+1;
				for (int k = j+1; k < (int) st.size(); k++) cout << " " << st[k]+1;
				cout << " " << st[j]+1 << "\n";
				return;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, a, b;
	cin >> N >> M;
	G.assign(N, vi());
	while(M--) {
		cin >> a >> b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);
	}
	solve();
	return 0;
}
