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
 
vi rooms, seg;
int N;
 
void makeTree(int x, int l, int r) {
	if (l == r) seg[x] = rooms[l];
	else {
		int mid = l + (r-l)/2;
		makeTree(2*x, l, mid);
		makeTree(2*x+1, mid+1, r);
		seg[x] = max(seg[2*x], seg[2*x+1]);
	}
}
 
void update(int x, int l, int r, int ind) {
	if (l > ind || r < ind) return;
	else if (l == r) seg[x] = rooms[ind];
	else {
		int mid = l + (r-l)/2;
		update(2*x, l, mid, ind);
		update(2*x+1, mid+1, r, ind);
		seg[x] = max(seg[2*x], seg[2*x+1]);
	}
}
 
int rmq(int x, int l, int r, int initInd, int endInd) {
	if (l > endInd || r < initInd) return -1;
	else if (l >= initInd && r <= endInd) return seg[x];
	else {
		int mid = l + (r-l)/2;
		int left = rmq(2*x, l, mid, initInd, endInd);
		int right = rmq(2*x+1, mid+1, r, initInd, endInd);
		if (left == -1) return right;
		if (right == -1) return left;
		return max(left, right);
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, cur;
	cin >> N >> M;
	rooms.assign(N, 0);
	seg.assign(4*N, 0);
	for (int i = 0; i < N; i++) cin >> rooms[i];
	makeTree(1, 0, N-1);
	for (int i = 0; i < M; i++) {
		cin >> cur;
		int lo = 0, hi = N-1, mid, ans = -1;
		while(lo <= hi) {
			mid = lo + (hi-lo)/2;
			if (rmq(1, 0, N-1, 0, mid) >= cur) {
				ans = mid;
				hi = mid-1;
			} else lo = mid+1;
		}
		if (ans != -1) {
			cout << ans+1 << " ";
			rooms[ans] = max(rooms[ans]-cur, 0);
			update(1, 0, N-1, ans);
		} else cout << "0 ";
	}
	return 0;
}
