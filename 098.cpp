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
 
vi seg, nums;
int N;
 
void makeTree(int x, int l, int r) {
	if (l == r) seg[x] = nums[l];
	else {
		int mid = l + (r-l)/2;
		makeTree(2*x, l, mid);
		makeTree(2*x+1, mid+1, r);
		seg[x] = min(seg[2*x], seg[2*x+1]);
	}
}
 
void update(int x, int l, int r, int pos) {
	if (l > pos || r < pos) return;
	if (l == r) seg[x] = nums[pos];
	else {
		int mid = l + (r-l)/2;
		update(2*x, l, mid, pos);
		update(2*x+1, mid+1, r, pos);
		seg[x] = min(seg[2*x], seg[2*x+1]);
	}
}
 
int query(int x, int l, int r, int initPos, int endPos) {
	if (initPos <= l && endPos >= r) return seg[x];
	else if (initPos > r || endPos < l) return -1;
	else {
		int mid = l + (r-l)/2;
		int left = query(2*x, l, mid, initPos, endPos);
		int right = query(2*x+1, mid+1, r, initPos, endPos);
		if (left == -1) return right;
		else if (right == -1) return left;
		else return min(left, right);
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, a, b, c;
	cin >> N >> Q;
	nums.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> nums[i];
	seg.assign(4*N, 0);
	makeTree(1, 0, N-1);
	while(Q--) {
		cin >> c >> a >> b;
		a--;
		if (c == 1) {
			nums[a] = b;
			update(1, 0, N-1, a);
		} else {
			b--;
			cout << query(1, 0, N-1, a, b) << "\n";
		}
	}
	return 0;
}
