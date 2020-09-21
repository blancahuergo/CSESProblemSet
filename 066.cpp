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
typedef pair<ll, int> pli;
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
vvpii G;
vl dist;

void Dijkstra() {
	dist.assign(N, LLONG_MAX);
	dist[0] = 0;
	priority_queue<pli> PQ;
	PQ.push(mp(0ll, 0));
	int u, v;
	ll distU, costV;
	pli curP;
	while(PQ.size()) {
		curP = PQ.top();
		PQ.pop();
		u = curP.second;
		distU = -curP.first;
		if (distU > dist[u]) continue;
		for (auto neigh: G[u]) {
			v = neigh.first;
			costV = neigh.second;
			if (dist[v] > distU+costV) {
				dist[v] = distU+costV;
				PQ.push(mp(-dist[v], v));
			}
		}
	}
	cout << "0";
	for (int i = 1; i < N; i++) cout << " " << dist[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	G.assign(N, vpii());
	int M, a, b, c;
	cin >> M;
	while(M--) {
		cin >> a >> b >> c;
		G[a-1].pb(mp(b-1, c));
	}
	Dijkstra();
	return 0;
}
