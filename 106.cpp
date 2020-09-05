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
typedef pair<pii, int> triple;
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
 
struct query {
	int l, r, root, ind;
	bool operator < (query& q2) {
		if (root != q2.root) return root < q2.root;
		else return r < q2.r;
	}
};
 
int Q;
map<int, int> dict;
vector<query> queries;
int cnt[200001];
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, a, b, lastA, lastB, val, hh;
	cin >> N >> Q;
	int ans[N], nums[N], cur;
	hh = 1;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		if (dict.find(cur) == dict.end()) {
			dict[cur] = hh;
			hh++;
		}
		nums[i] = dict[cur];
	}
	int sq = 600;
	queries.assign(Q, query());
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		queries[i].l = a-1;
		queries[i].r = b-1;
		queries[i].ind = i;
		queries[i].root = (a-1)/sq;
	}
	sort(queries.begin(), queries.end());
	lastA = queries[0].l;
	lastB = queries[0].r;
	val = 0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = lastA; i <= lastB; i++) {
		cnt[nums[i]]++;
		if (cnt[nums[i]] == 1) val++;
	}
	ans[queries[0].ind] = val;
	for (int i = 1; i < Q; i++) {
		a = queries[i].l;
		b = queries[i].r;
		for (int j = lastA-1; j >= a; j--) {
			cnt[nums[j]]++;
			if (cnt[nums[j]] == 1) val++;
		}
		for (int j = lastA; j < a; j++) {
			cnt[nums[j]]--;
			if (cnt[nums[j]] == 0) val--;
		}
		for (int j = lastB+1; j <= b; j++) {
			cnt[nums[j]]++;
			if (cnt[nums[j]] == 1) val++;
		}
		for (int j = lastB; j > b; j--) {
			cnt[nums[j]]--;
			if (cnt[nums[j]] == 0) val--;
		}
		ans[queries[i].ind] = val;
		lastA = a;
		lastB = b;
	}
	for (int i = 0; i < Q; i++) cout << ans[i] << "\n";
	return 0;
}
