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
vvl G;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, Q, a, b, c;
	cin >> N >> M >> Q;
	G.assign(N, vl(N, 1e18));
	while(M--) {
		cin >> a >> b >> c;
		G[a-1][b-1] = min(G[a-1][b-1], (ll) c);
		G[b-1][a-1] = min(G[b-1][a-1], (ll) c);
	}
	for (int i = 0; i < N; i++) {
		G[i][i] = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				G[j][k] = min(G[j][k], G[j][i] + G[i][k]);
			}
		}
	}
	while(Q--) {
		cin >> a >> b;
		if (G[a-1][b-1] == 1e18) cout << "-1\n";
		else cout << G[a-1][b-1] << "\n";
	}
	return 0;
}
