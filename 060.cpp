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
 
int N, M, cnt, grid[1000][1000];
vvi dist;
 
void bfs(int r, int c) {
	queue<int> row, col;
	row.push(r);
	col.push(c);
	dist[r][c] = 0;
	while(row.size()) {
		r = row.front();
		row.pop();
		c = col.front();
		col.pop();
		if (r > 0 && grid[r-1][c] && dist[r-1][c] > dist[r][c]+1) {
			dist[r-1][c] = dist[r][c]+1;
			row.push(r-1);
			col.push(c);
		}
		if (r < N-1 && grid[r+1][c] && dist[r+1][c] > dist[r][c]+1) {
			dist[r+1][c] = dist[r][c]+1;
			row.push(r+1);
			col.push(c);
		}
		if (c > 0 && grid[r][c-1] && dist[r][c-1] > dist[r][c]+1) {
			dist[r][c-1] = dist[r][c]+1;
			row.push(r);
			col.push(c-1);
		}
		if (c < M-1 && grid[r][c+1] && dist[r][c+1] > dist[r][c]+1) {
			dist[r][c+1] = dist[r][c]+1;
			row.push(r);
			col.push(c+1);
		}
	}
}
 
void trace_back(int r, int c) {
	if (dist[r][c] == 0) {
		cout << cnt << "\n";
		return;
	}
	cnt++;
	if (r && dist[r][c] == dist[r-1][c]+1) {
		trace_back(r-1, c);
		cout << "D";
	} else if (r < N-1 && dist[r][c] == dist[r+1][c]+1) {
		trace_back(r+1, c);
		cout << "U";
	} else if (c && dist[r][c] == dist[r][c-1]+1) {
		trace_back(r, c-1);
		cout << "R";
	} else {
		trace_back(r, c+1);
		cout << "L";
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	memset(grid, 1, sizeof(grid));
	dist.assign(N, vi(M, 1e8));
	pii fir, sec;
	char c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			if (c == '#') grid[i][j] = 0;
			else if (c == 'A') fir = mp(i, j);
			else if (c == 'B') sec = mp(i, j);
		}
	}
	bfs(fir.f, fir.s);
	if (dist[sec.f][sec.s] == 1e8) cout << "NO\n";
	else {
		cout << "YES\n";
		trace_back(sec.f, sec.s);
	}
	return 0;
}
