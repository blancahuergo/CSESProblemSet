#include <iostream>
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
 
int N, K;
vl nums;
 
bool check(ll sm) {
	int count = 1;
	ll curSm = 0;
	for (int i = 0; i < N; i++) {
		if (nums[i] > sm) return false;
		curSm += nums[i];
		if (curSm > sm) {
			count++;
			curSm = nums[i];
		}
	}
	return count <= K;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	nums = vl(N);
	for (int i = 0; i < N; i++) cin >> nums[i];
	ll lo = 0, hi = 2e18, mid, ans;
	while(lo <= hi) {
		mid = lo + (hi-lo)/2;
		if (check(mid)) {
			ans = mid;
			hi = mid-1;
		} else lo = mid+1;
	}
	cout << ans << "\n";
	return 0;
}
