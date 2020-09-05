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
vector<pair<int, pair<int, int>>> proj;
 
bool cmp(pair<int, pii> A, pair<int, pii> B) {
	if (A.s.s != B.s.s) return A.s.s < B.s.s;
	else return A.s.f < B.s.f;
}
 
int compressCoords() {
	int a, b, p, cnt;
	map<int, int> nums;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> p;
		proj[i] = mp(p, mp(a, b));
		nums[a] = 0;
		nums[b] = 0;
	}
	map<int, int>::iterator it;
	it = nums.begin();
	cnt = 0;
	while(it != nums.end()) {
		nums[it->first] = cnt;
		cnt++;
		it++;
	}
	for (int i = 0; i < N; i++) {
		proj[i].s.f = nums[proj[i].s.f];
		proj[i].s.s = nums[proj[i].s.s];
	}
	return nums.size();
}
 
ll solve(int maxT) {
	vl cur;
	cur.assign(maxT, 0ll);
	int startT, j = 0;
	sort(proj.begin(), proj.end(), cmp);
	for (int i = 0; i < maxT; i++) {
		if (i) cur[i] = cur[i-1];
		while (j < N) {
			if (proj[j].s.s > i) break;
			startT = proj[j].s.f;
			if (startT) cur[i] = max(cur[i], cur[startT-1] + proj[j].f);
			else cur[i] = max(cur[i], (ll) proj[j].f);
			j++;
		}
	}
	return cur[maxT-1];
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int maxT;
	cin >> N;
	proj.assign(N, pair<int, pair<int, int>>());
	maxT = compressCoords();
	cout << solve(maxT) << "\n";
	return 0;
}
