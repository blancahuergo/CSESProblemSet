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

int N;
vvi G;
vi pre;

int BFS() {
	vi dist = vi(N, INT_MAX);
	pre.assign(N, -1);
	dist[0] = 0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		int u = Q.front();
		Q.pop();
		for (auto v: G[u]) {
			if (dist[v] > dist[u]+1) {
				dist[v] = dist[u]+1;
				pre[v] = u;
				Q.push(v);
			}
		}
	}
	if (dist[N-1] == INT_MAX) dist[N-1] = -1;
	return dist[N-1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	G.assign(N, vi());
	int M, a, b;
	cin >> M;
	while(M--) {
		cin >> a >> b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);
	}
	int ans = BFS();
	if (ans == -1) cout << "IMPOSSIBLE";
	else {
		cout << ans+1 << "\n";
		a = N-1;
		stack<int> st;
		while(a != -1) {
			st.push(a+1);
			a = pre[a];
		}
		cout << st.top();
		st.pop();
		while(!st.empty()) {
			cout << " " << st.top();
			st.pop();
		}
	}
	return 0;
}
