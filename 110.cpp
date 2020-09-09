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
	ll val;
	Node* l;
	Node* r;
	Node(ll num, Node* left = NULL, Node* right = NULL) {
		val = num;
		l = left;
		r = right;
	}
};

int N;
vl nums;
vector<Node*> roots;
vi kToRoot;

void build(Node* cur, int l, int r) {
	if (l == r) {
		cur->val = nums[l];
	} else {
		int mid = l + (r-l)/2;
		cur->l = new Node(0ll);
		cur->r = new Node(0ll);
		build(cur->l, l, mid);
		build(cur->r, mid+1, r);
		cur->val = cur->l->val + cur->r->val;
	}
}

void update(Node* old, Node* cur, int l, int r, int ind, int val) {
	if (l > ind || r < ind) return;
	if (l == r) cur->val = val;
	else {
		int mid = l + (r-l)/2;
		if (ind <= mid) {
			cur->r = old->r;
			cur->l = new Node(0ll);
			update(old->l, cur->l, l, mid, ind, val);
		} else {
			cur->l = old->l;
			cur->r = new Node(0ll);
			update(old->r, cur->r, mid+1, r, ind, val);
		}
		cur->val = cur->l->val + cur->r->val;
	}
}

ll query(Node* cur, int l, int r, int initInd, int endInd) {
	if (l > endInd || r < initInd) return 0ll;
	if (l >= initInd && r <= endInd) return cur->val;
	else {
		int mid = l + (r-l)/2;
		ll left = query(cur->l, l, mid, initInd, endInd);
		ll right = query(cur->r, mid+1, r, initInd, endInd);
		return left+right;
	}
}

void insert(int k) {
	kToRoot.pb(kToRoot[k]);
}

void setVal(int k, int nod, int val) {
	Node* rt = roots[kToRoot[k]];
	Node* newRt = new Node(0ll);
	roots.pb(newRt);
	kToRoot[k] = (int) roots.size()-1;
	update(rt, newRt, 0, N-1, nod, val);
}

ll rsq(int k, int l, int r) {
	return query(roots[kToRoot[k]], 0, N-1, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, typ, k, a, x, b;
	cin >> N >> Q;
	nums.assign(N, 0ll);
	for (int i = 0; i < N; i++) cin >> nums[i];
	Node* rt = new Node(0ll);
	build(rt, 0, N-1);
	roots.pb(rt);
	kToRoot.pb(0);
	while(Q--) {
		cin >> typ;
		if (typ == 1) {
			cin >> k >> a >> x;
			setVal(k-1, a-1, x);
		} else if (typ == 2) {
			cin >> k >> a >> b;
			cout << rsq(k-1, a-1, b-1) << "\n";
		} else {
			cin >> k;
			insert(k-1);
		}
	}
	return 0;
}
