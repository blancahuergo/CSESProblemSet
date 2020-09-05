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
vvi grid, bit;
 
int sumC(int r, int c) {
	int ret = 0;
	while(c >= 0) {
		ret += bit[r][c];
		c = (c&(c+1)) - 1;
	}
	return ret;
}
 
int sum(int r, int c) {
	int ret = 0;
	while(r >= 0) {
		ret += sumC(r, c);
		r = (r&(r+1)) - 1;
	}
	return ret;
}
 
int query(int r1, int c1, int r2, int c2) {
	int ans = sum(r2, c2);
	if (r1) ans -= sum(r1-1, c2);
	if (c1) ans -= sum(r2, c1-1);
	if (r1 && c1) ans += sum(r1-1, c1-1);
	return ans;
}
 
void addC(int r, int c, int val) {
	while(c < N) {
		bit[r][c] += val;
		c = c | (c+1);
	}
}
 
void add(int r, int c, int val) {
	while(r < N) {
		addC(r, c, val);
		r = r | (r+1);
	}
}
 
void flip(int r, int c) {
	grid[r][c] = 1 - grid[r][c];
	if (grid[r][c]) add(r, c, 1);
	else add(r, c, -1);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q;
	string S;
	cin >> N >> Q;
	grid.assign(N, vi(N, 0));
	bit.assign(N, vi(N, 0));
	for (int i = 0; i < N; i++) {
		cin >> S;
		for (int j = 0; j < N; j++) {
			if (S[j] == '*') {
				grid[i][j] = 1;
				add(i, j, 1);
			}
		}
	}
	int typ, r, c, r1, c1, r2, c2;
	while(Q--) {
		cin >> typ;
		if (typ == 1) {
			cin >> r >> c;
			flip(r-1, c-1);
		} else {
			cin >> r1 >> c1 >> r2 >> c2;
			cout << query(r1-1, c1-1, r2-1, c2-1) << "\n";
		}
	}
	return 0;
}
