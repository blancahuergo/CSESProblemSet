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
vi nums, last;
 
int findPos(int A) {
	int lo = 0, hi = (int) last.size()-1, mid, ret=0;
	while(lo <= hi) {
		mid = lo + (hi-lo)/2;
		if (last[mid] == A) return mid;
		else if (last[mid] < A) {
			ret = mid;
			lo = mid+1;
		} else hi = mid-1;
	}
	return ret+1;
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	nums = vi(N);
	for (int i = 0; i < N; i++) cin >> nums[i];
	last = vi();
	last.pb(nums[0]);
	int pos, len = 1;
	for (int i = 1; i < N; i++) {
		if (nums[i] < last[0]) {
			last[0] = nums[i];
		} else if (nums[i] > last[len-1]) {
			last.pb(nums[i]);
			len++;
		} else if (nums[i] == last[len-1]) continue;
		else {
			pos = findPos(nums[i]);
			last[pos] = nums[i];
		}
	}
	cout << len;
	return 0;
}
