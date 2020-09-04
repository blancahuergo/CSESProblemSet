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
	int N, cur;
	cin >> N;
	vpii nums(N);
	for (int i = 0; i < N; i++) {
		cin >> cur;
		nums[i] = mp(cur, i+1);
	}
	sort(nums.begin(), nums.end());
	set<int> pos;
	set<int>::iterator it;
	vi ans(N);
	vi toAdd = {nums[0].s};
	for (int i = 1; i < N; i++) {
		if (nums[i].f == nums[i-1].f) {
			toAdd.pb(nums[i].s);
			continue;
		} else {
			for (int j = 0; j < (int) toAdd.size(); j++) {
				cur = toAdd[j];
				if (pos.empty() || cur < *(pos.begin())) ans[cur-1] = 0;
				else if (cur > *(pos.rbegin())) ans[cur-1] = *(pos.rbegin());
				else {
					it = pos.lower_bound(cur);
					it--;
					ans[cur-1] = *it;
				}
			}
			for (int j = 0; j < (int) toAdd.size(); j++) pos.insert(toAdd[j]);
			toAdd.clear();
			toAdd.pb(nums[i].s);
		}
	}
	for (int i = 0; i < (int) toAdd.size(); i++) {
		cur = toAdd[i];
		if (pos.empty() || cur < *(pos.begin())) ans[cur-1] = 0;
		else if (cur > *(pos.rbegin())) ans[cur-1] = *(pos.rbegin());
		else {
			it = pos.lower_bound(cur);
			it--;
			ans[cur-1] = *it;
		}
	}
	for (int i = 0; i < N; i++) cout << ans[i] << " ";
	return 0;
}
