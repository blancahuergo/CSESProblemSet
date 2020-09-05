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
 
vvi DP;
 
int cuttings(int a, int b) {
	if (DP[a][b] != -1) return DP[a][b];
	int ans = 1e9;
	for (int lo = 1; lo < a; lo++) ans = min(ans, 1+ cuttings(lo, b) + cuttings(a-lo, b));
	for (int lo = 1; lo < b; lo++) ans = min(ans, 1 + cuttings(lo, a) + cuttings(b-lo, a));
	return DP[a][b] = DP[b][a] = ans;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	DP.assign(501, vi(501, -1));
	for (int i = 1; i <= 500; i++) DP[i][i] = 0;
	int a, b;
	cin >> a >> b;
	cout << cuttings(a, b);
	return 0;
}
