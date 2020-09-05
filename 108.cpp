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
 
struct Node {
	ll sum, setValue, addValue;
	bool setUpdated;
	void resetVars() {
		addValue = setValue = 0ll;
		setUpdated = false;
	}
};
 
int N;
vl nums;
vector<Node> seg;
 
void buildSeg(int x, int l, int r) {
	if (l == r) {
		seg[x].resetVars();
		seg[x].sum = nums[l];
	} else {
		int mid = l + (r-l)/2;
		buildSeg(2*x, l, mid);
		buildSeg(2*x+1, mid+1, r);
		seg[x].resetVars();
		seg[x].sum = seg[2*x].sum + seg[2*x+1].sum;
	}
}
 
void push(int x, int par) {
	if (seg[par].setUpdated) {
		seg[x].setValue = seg[par].setValue;
		seg[x].addValue = seg[par].addValue;
		seg[x].setUpdated = true;
	} else seg[x].addValue += seg[par].addValue;
}
 
void calc(int x, int l, int r) {
	if (seg[x].setUpdated) seg[x].sum = (r-l+1)*(seg[x].setValue+seg[x].addValue);
	else seg[x].sum += (r-l+1)*seg[x].addValue;
	if (l != r) {
		push(2*x, x);
		push(2*x+1, x);
	}
	seg[x].resetVars();
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
		return left+right;
	}
}
 
void addToRange(int x, int l, int r, int initInd, int endInd, ll add) {
	if (l > endInd || r < initInd) return;
	if (l >= initInd && r <= endInd) seg[x].addValue += add;
	else {
		calc(x, l, r);
		int mid = l + (r-l)/2;
		addToRange(2*x, l, mid, initInd, endInd, add);
		addToRange(2*x+1, mid+1, r, initInd, endInd, add);
		calc(2*x, l, mid);
		calc(2*x+1, mid+1, r);
		seg[x].sum = seg[2*x].sum + seg[2*x+1].sum;
	}
}
 
void setRange(int x, int l, int r, int initInd, int endInd, ll setVal) {
	if (l > endInd || r < initInd) return;
	if (l >= initInd && r <= endInd) {
		seg[x].setValue = setVal;
		seg[x].setUpdated = true;
		seg[x].addValue = 0ll;
	} else {
		calc(x, l, r);
		int mid = l + (r-l)/2;
		setRange(2*x, l, mid, initInd, endInd, setVal);
		setRange(2*x+1, mid+1, r, initInd, endInd, setVal);
		calc(2*x, l, mid);
		calc(2*x+1, mid+1, r);
		seg[x].sum = seg[2*x].sum + seg[2*x+1].sum;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, typ, a, b, x;
	cin >> N >> Q;
	nums.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> nums[i];
	seg.assign(4*N, Node());
	buildSeg(1, 0, N-1);
	while(Q--) {
		cin >> typ >> a >> b;
		a--;
		b--;
		if (typ == 1) {
			cin >> x;
			addToRange(1, 0, N-1, a, b, x);
		} else if (typ == 2) {
			cin >> x;
			setRange(1, 0, N-1, a, b, x);
		} else {
			cout << query(1, 0, N-1, a, b) << "\n";
		}
	}
	return 0;
}
