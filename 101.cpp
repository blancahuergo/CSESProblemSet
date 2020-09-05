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
vvi grid;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, x1, y1, x2, y2;
	char c;
	cin >> N >> Q;
	grid.assign(N, vi(N, 0));
	cin >> c;
	if (c == '*') grid[0][0] = 1;
	for (int j = 1; j < N; j++) {
		cin >> c;
		grid[0][j] = grid[0][j-1];
		if (c == '*') grid[0][j]++;
	}
	for (int i = 1; i < N; i++) {
		cin >> c;
		grid[i][0] = grid[i-1][0];
		if (c == '*') grid[i][0]++;
		for (int j = 1; j < N; j++) {
			cin >> c;
			if (c == '*') grid[i][j] = 1;
			grid[i][j] += grid[i-1][j];
			grid[i][j] += grid[i][j-1];
			grid[i][j] -= grid[i-1][j-1];
		}
	}
	while(Q--) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		x2--;
		y2--;
		int ans = grid[x2][y2];
		if (x1) {
			ans -= grid[x1-1][y2];
			if (y1) {
				ans -= grid[x2][y1-1];
				ans += grid[x1-1][y1-1];
			}
		} else if (y1) {
			ans -= grid[x2][y1-1];
		}
		cout << ans << "\n";
	}
	return 0;
}
