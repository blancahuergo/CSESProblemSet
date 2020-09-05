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
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	ll mod = 1e9 + 7;
	cin >> N >> M;
	ll arr[N];
	vvl DP;
	DP.assign(N, vl(M, 0ll));
	ll ans = 1ll;
	cin >> arr[0];
	for (int i = 1; i < N; i++) {
		cin >> arr[i];
		if ((abs(arr[i] - arr[i-1]) > 1) && (min(arr[i], arr[i-1]) != 0)) ans = 0ll;
	}
	if (arr[0] == 0) for (int i = 0; i < M; i++) DP[0][i] = 1;
	else DP[0][arr[0]-1] = 1;
	for (int i = 1; i < N; i++) {
		if (arr[i] != 0) {
			if (arr[i] > 1 && arr[i] < M) DP[i][arr[i]-1] = (DP[i-1][arr[i]-2] + DP[i-1][arr[i]] + DP[i-1][arr[i]-1])%mod;
			else if (arr[i] == 1) {
				if (M > 1) DP[i][0] = (DP[i-1][0] + DP[i-1][1])%mod;
				else DP[i][0] = DP[i-1][0];
			}
			else {
				if (M > 1) DP[i][M-1] = (DP[i-1][M-2] + DP[i-1][M-1])%mod;
				else DP[i][0] = DP[i-1][0];
			}
		} else {
			if (M > 1) {
				DP[i][0] = (DP[i-1][0] + DP[i-1][1]) % mod;
				DP[i][M-1] = (DP[i-1][M-1] + DP[i-1][M-2]) % mod;
			} else DP[i][0] = DP[i-1][0];
			for (int j = 1; j < M-1; j++) {
				DP[i][j] = (DP[i-1][j-1] + DP[i-1][j] + DP[i-1][j+1]) % mod;
			}
		}
	}
	if (!ans) cout << "0\n";
	else {
		ans = 0ll;
		for (int i = 0; i < M; i++) {
			ans += DP[N-1][i];
			ans %= mod;
		}
		cout << ans << "\n";
	}
	return 0;
}
