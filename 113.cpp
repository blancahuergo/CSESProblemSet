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
 
int diam() {
	vi dist(N, N+1);
	dist[0] = 0;
	queue<int> Q;
	Q.push(0);
	int u, v, fur;
	while(Q.size()) {
		u = Q.front();
		Q.pop();
		fur = u;
		for (int i = 0; i < (int) G[u].size(); i++) {
			v = G[u][i];
			if (dist[v] > dist[u]+1) {
				dist[v] = dist[u]+1;
				Q.push(v);
			}
		}
	}
	dist.assign(N, N+1);
	dist[fur] = 0;
	Q.push(fur);
	while(Q.size()) {
		u = Q.front();
		Q.pop();
		fur = u;
		for (int i = 0; i < (int) G[u].size(); i++) {
			v = G[u][i];
			if (dist[v] > dist[u]+1) {
				dist[v] = dist[u]+1;
				Q.push(v);
			}
		}
	}
	return dist[fur];
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	G.assign(N, vi());
	int a, b;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);
	}
	cout << diam();
	return 0;
}
