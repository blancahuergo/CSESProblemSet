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
 
struct node {
	ll cnt, start, sum;
	node() {
		cnt = start = sum = 0ll;
	}
	void reset() {
		cnt = start = 0ll;
	}
};
 
vector<node> seg;
vl nums;
int N;
 
void buildTree(int x, int l, int r) {
	if (l == r) seg[x].sum = nums[l];
	else {
		int mid = l + (r-l)/2;
		buildTree(2*x, l, mid);
		buildTree(2*x+1, mid+1, r);
		seg[x].sum = seg[2*x].sum + seg[2*x+1].sum;
	}
}
 
ll sumProg(ll first, ll diff, ll terms) {
	return terms*(2*first + (terms-1)*diff)/2;
}
 
void push(int x, int par, int len, bool left) {
	if (left) {
		seg[x].start += seg[par].start;
		seg[x].cnt += seg[par].cnt;
	} else {
		seg[x].start += seg[par].start + seg[par].cnt*len;
		seg[x].cnt += seg[par].cnt;
	}
}
 
void calc(int x, int l, int r) {
	if (seg[x].cnt == 0) return;
	ll len = r-l+1;
	seg[x].sum += (seg[x].start-seg[x].cnt)*len + sumProg(seg[x].cnt, seg[x].cnt, len);
	if (l != r) {
		int len2 = (r-l)/2 + 1;
		push(2*x, x, len2, true);
		push(2*x+1, x, len2, false);
	}
	seg[x].reset();
}
 
void update(int x, int l, int r, int initInd, int endInd) {
	if (l > endInd || r < initInd) return;
	if (l >= initInd && r <= endInd) {
		seg[x].cnt++;
		seg[x].start += l - initInd + 1;
	} else {
		calc(x, l, r);
		int mid = l + (r-l)/2;
		update(2*x, l, mid, initInd, endInd);
		update(2*x+1, mid+1, r, initInd, endInd);
		calc(2*x, l, mid);
		calc(2*x+1, mid+1, r);
		seg[x].sum = seg[2*x].sum + seg[2*x+1].sum;
	}
}
 
ll query(int x, int l, int r, int initInd, int endInd) {
	if (l > endInd || r < initInd) return -1;
	calc(x, l, r);
	if (l >= initInd && r <= endInd) return seg[x].sum;
	else {
		int mid = l + (r-l)/2;
		ll left = query(2*x, l, mid, initInd, endInd);
		ll right = query(2*x+1, mid+1, r, initInd, endInd);
		if (left == -1) return right;
		if (right == -1) return left;
		return left + right;
	}
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, typ, a, b;
	cin >> N >> Q;
	seg.assign(4*N, node());
	nums.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> nums[i];
	buildTree(1, 0, N-1);
	while(Q--) {
		cin >> typ >> a >> b;
		if (typ == 1) update(1, 0, N-1, a-1, b-1);
		else cout << query(1, 0, N-1, a-1, b-1) << "\n";
	}
	return 0;
}
