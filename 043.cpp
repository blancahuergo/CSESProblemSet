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
 
vl prefSum, logs;
vvl table;
int N, height;
 
void precomputation() {
	logs.assign(N+2, 0ll);
	for (int i = 2; i <= N+1; i++) logs[i] = logs[i/2]+1;
	height = (int) ceil(log2((double) (N+1)));
	table.assign(N+1, vl(height));
	for (int i = 0; i <= N; i++) table[i][0] = prefSum[i];
	for (int j = 1; j <= height; j++) {
		for (int i = 0; i + (1<<j) <= N+1; i++) {
			table[i][j] = min(table[i][j-1], table[i + (1<<(j-1))][j-1]);
		}
	}
}
 
ll minRange(int l, int r) {
	int j = logs[r - l + 1];
	return min(table[l][j], table[r - (1 << j) + 1][j]);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, cur;
	cin >> N >> a >> b;
	prefSum.assign(N+1, 0ll);
	for (int i = 1; i <= N; i++) {
		cin >> cur;
		prefSum[i] = prefSum[i-1]+cur;
	}
	precomputation();
	ll ans = LLONG_MIN;
	for (int i = max(1, a); i <= N; i++) {
		ans = max(ans, prefSum[i] - minRange(max(0, i-b), i-a));
	}
	cout << ans;
	return 0;
}
