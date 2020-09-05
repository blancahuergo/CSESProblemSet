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
 
int N;
vvl DP;
vi nums;
 
ll maxPos(int l, int r) {
	if (l > r) return 0;
	if (DP[l][r] != -1) return DP[l][r];
	if (l == r) return DP[l][r] = nums[l];
	return DP[l][r] = max(min(maxPos(l+2, r), maxPos(l+1, r-1)) + nums[l], min(maxPos(l+1, r-1), maxPos(l, r-2)) + nums[r]);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	DP.assign(N, vl(N, -1));
	nums.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> nums[i];
	cout << maxPos(0, N-1);
	return 0;
}
