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
 
vi DP;
 
int dig (int N) {
	if (N == 0) return 0;
	if (DP[N] != -1) return DP[N];
	if (N < 10) return DP[N] = 1;
	string S = to_string(N);
	int ans = 1e9;
	for (int i = 0; i < (int) S.length(); i++) {
		if (S[i] == '0') continue;
		ans = min(ans, 1+dig(N - ((int)(S[i]-'0'))));
	}
	return DP[N] = ans;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	DP.assign(N+1, -1);
	cout << dig(N);
	return 0;
}
