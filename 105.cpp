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
typedef pair<int, ll> pil;
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
	ll maxSum = 0ll, sumPref = 0ll, sumSuf = 0ll, totSum = 0ll;
};
 
vector<Node> seg;
vl vals;
int N;
 
void buildSegTree(int x, int l, int r) {
	if (l == r)	seg[x].totSum = seg[x].maxSum = seg[x].sumPref = seg[x].sumSuf = vals[l];
	else {
		int mid = l + (r-l)/2;
		buildSegTree(2*x, l, mid);
		buildSegTree(2*x+1, mid+1, r);
		seg[x].sumPref = max(seg[2*x].sumPref, seg[2*x].totSum + max(seg[2*x+1].sumPref, 0ll));
		seg[x].sumSuf = max(seg[2*x+1].sumSuf, seg[2*x+1].totSum + max(seg[2*x].sumSuf, 0ll));
		seg[x].maxSum = max(max(seg[x].sumPref, seg[x].sumSuf), seg[2*x].sumSuf + seg[2*x+1].sumPref);
		seg[x].maxSum = max(seg[x].maxSum, max(seg[2*x].maxSum, seg[2*x+1].maxSum));
		seg[x].totSum = seg[2*x].totSum + seg[2*x+1].totSum;
	}
}
 
void updateSegTree(int x, int l, int r, int ind) {
	if (l > ind || r < ind) return;
	if (l == r) seg[x].totSum = seg[x].maxSum = seg[x].sumPref = seg[x].sumSuf = vals[l];
	else {
		int mid = l + (r-l)/2;
		updateSegTree(2*x, l, mid, ind);
		updateSegTree(2*x+1, mid+1, r, ind);
		seg[x].sumPref = max(seg[2*x].sumPref, seg[2*x].totSum + max(seg[2*x+1].sumPref, 0ll));
		seg[x].sumSuf = max(seg[2*x+1].sumSuf, seg[2*x+1].totSum + max(seg[2*x].sumSuf, 0ll));
		seg[x].maxSum = max(max(seg[x].sumPref, seg[x].sumSuf), seg[2*x].sumSuf + seg[2*x+1].sumPref);
		seg[x].maxSum = max(seg[x].maxSum, max(seg[2*x].maxSum, seg[2*x+1].maxSum));
		seg[x].totSum = seg[2*x].totSum + seg[2*x+1].totSum;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, a, b;
	cin >> N >> Q;
	vals.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> vals[i];
	seg.assign(4*N, Node());
	buildSegTree(1, 0, N-1);
	while(Q--) {
		cin >> a >> b;
		a--;
		vals[a] = b;
		updateSegTree(1, 0, N-1, a);
		cout << max(0ll, seg[1].maxSum) << "\n";
	}
	return 0;
}
