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
vi DP;
 
int dfs(int S) {
	if (DP[S] != -1) return DP[S];
	int ans = 0;
	for (int i = 0; i < (int) G[S].size(); i++) ans += 1+dfs(G[S][i]);
	return DP[S] = ans;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	DP.assign(N, -1);
	G.assign(N, vi());
	int par;
	for (int i = 1; i < N; i++) {
		cin >> par;
		G[par-1].pb(i);
	}
	dfs(0);
	cout << DP[0];
	for (int i = 1; i < N; i++) cout << " " << DP[i];
	return 0;
}
