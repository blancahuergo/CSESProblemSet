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
 
vl bit;
int N;
 
void add(int num, int pos) {
	while(pos < N) {
		bit[pos] += num;
		pos = pos | (pos+1);
	}
}
 
ll sum(int r) {
	ll ret = 0ll;
	while(r >= 0) {
		ret += bit[r];
		r = (r & (r+1)) - 1;
	}
	return ret;
}
 
ll RSQ(int l, int r) {
	ll ans = sum(r);
	if (l != 0) ans -= sum(l-1);
	return ans;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cur, Q, c, a, b;
	cin >> N >> Q;
	bit.assign(N, 0ll);
	vl val;
	val.assign(N, 0ll);
	for (int i = 0; i < N; i++) {
		cin >> cur;
		add(cur, i);
		val[i] = cur;
	}
	while(Q--) {
		cin >> c >> a >> b;
		if (c == 1) {
			a--;
			add(b - val[a], a);
			val[a] = b;
		} else if (a == b) cout << val[a-1] << "\n";
		else cout << RSQ(a-1, b-1) << "\n";
	}
	return 0;
}
