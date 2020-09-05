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
 
vl val, seg, lazy;
int N;
 
void makeTree(int x, int l, int r) {
	if (l == r) seg[x] = val[l];
	else {
		int mid = l + (r-l)/2;
		makeTree(2*x, l, mid);
		makeTree(2*x+1, mid+1, r);
		seg[x] = seg[2*x]+seg[2*x+1];
	}
}
 
void update(int x, int l, int r, int initInd, int endInd, int add) {
	if (initInd > r || endInd < l) return;
	else if (l >= initInd && r <= endInd) lazy[x] += add;
	else {
		int mid = l + (r-l)/2;
		update(2*x, l, mid, initInd, endInd, add);
		update(2*x+1, mid+1, r, initInd, endInd, add);
	}
}
 
void query(int x, int l, int r, int ind) {
	if (l > ind || r < ind) return;
	else if (l == r) {
		seg[x] += lazy[x];
		lazy[x] = 0ll;
	} else {
		int mid = l + (r-l)/2;
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		query(2*x, l, mid, ind);
		query(2*x+1, mid+1, r, ind);
		seg[x] = seg[2*x]+seg[2*x+1]+lazy[x];
		lazy[x] = 0ll;
	}
}
 
ll getVal(int x, int l, int r, int ind) {
	if (l > ind || r < ind) return -1;
	else if (l == r) return seg[x];
	else {
		int mid = l + (r-l)/2;
		ll left = getVal(2*x, l, mid, ind);
		ll right = getVal(2*x+1, mid+1, r, ind);
		if (left == -1) return right;
		if (right == -1) return left;
		return left+right;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, a, b, c, d;
	cin >> N >> Q;
	val.assign(N, 0ll);
	for (int i = 0; i < N; i++) cin >> val[i];
	seg.assign(4*N, 0ll);
	lazy.assign(4*N, 0ll);
	makeTree(1, 0, N-1);
	while(Q--) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, 0, N-1, b-1, c-1, d);
		} else {
			cin >> b;
			b--;
			query(1, 0, N-1, b);
			cout << getVal(1, 0, N-1, b) << "\n";
		}
	}
	return 0;
}
