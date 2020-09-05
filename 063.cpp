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
 
vi C;
vvi G;
int N;
bool pos;
 
void dfs(int S) {
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (C[v] == -1) {
			C[v] = 1-C[S];
			dfs(v);
		} else if (C[v] == C[S]) pos = false;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, a, b;
	cin >> N >> M;
	C.assign(N, -1);
	G.assign(N, vi());
	while(M--) {
		cin >> a >> b;
		a--;
		b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	pos = true;
	for (int i = 0; i < N; i++) {
		if (C[i] == -1) {
			C[i] = 1;
			dfs(i);
		}
	}
	if (pos) {
		cout << C[0]+1;
		for (int i = 1; i < N; i++) cout << " " << C[i]+1;
		cout << "\n";
	} else cout << "IMPOSSIBLE\n";
	return 0;
}
