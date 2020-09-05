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
vi C, arr, pos, subT;
 
bool cmp(pii A, pii B) {
	if (A.first/sqrt(N) != B.first/sqrt(N)) {
		return A.first/sqrt(N) < B.first/sqrt(N);
	} else return A.second <= B.second;
}
 
void dfs(int S, int p) {
	arr.pb(S);
	pos[S] = (int) arr.size()-1;
	subT[S] = 0;
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (v == p) continue;
		dfs(v, S);
		subT[S] += 1+subT[v];
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	C.assign(N, 0);
	pos.assign(N, 0);
	subT.assign(N, 0);
	G.assign(N, vi());
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	int a, b;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		a--;
		b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(0, -1);
	vpii Q(N);
	unordered_map<int, int> cols;
	for (int i = 0; i < N; i++) Q[i] = mp(pos[i], pos[i]+subT[i]);
	sort(Q.begin(), Q.end(), cmp);
	int lastL = Q[0].first, lastR = Q[0].second, curL, curR;
	vi ret(N);
	for (int i = lastL; i <= lastR; i++) {
		cols[C[arr[i]]]++;;
	}
	ret[arr[lastL]] = (int) cols.size();
	for (int i = 1; i < N; i++) {
		curL = Q[i].first;
		curR = Q[i].second;
		if (curL < lastL) {
			for (int j = lastL-1; j >= curL; j--) {
				cols[C[arr[j]]]++;;
			}
		} else if (curL > lastL) {
			for (int j = lastL; j < curL; j++) {
				cols[C[arr[j]]]--;
				if (cols[C[arr[j]]] == 0) cols.erase(C[arr[j]]);
			}
		}
		if (curR > lastR) {
			for (int j = lastR+1; j <= curR; j++) {
				cols[C[arr[j]]]++;
			}
		} else if (curR < lastR) {
			for (int j = lastR; j > curR; j--) {
				cols[C[arr[j]]]--;
				if (cols[C[arr[j]]] == 0) cols.erase(C[arr[j]]);
			}
		}
		ret[arr[curL]] = (int) cols.size();
		lastL = curL;
		lastR = curR;
	}
	cout << ret[0];
	for (int i = 1; i < N; i++) cout << " " << ret[i];
	return 0;
}
