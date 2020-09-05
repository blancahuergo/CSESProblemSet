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
 
int N, M;
vector<string> grid;
vvi vis;
 
void dfs(int r, int c) {
	vis[r][c] = true;
	if (r > 0 && grid[r-1][c] != '#' && (!vis[r-1][c])) dfs(r-1, c);
	if (r < N-1 && grid[r+1][c] != '#' && (!vis[r+1][c])) dfs(r+1, c);
	if (c > 0 && grid[r][c-1] != '#' && (!vis[r][c-1])) dfs(r, c-1);
	if (c < M-1 && grid[r][c+1] != '#' && (!vis[r][c+1])) dfs(r, c+1);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	grid = vector<string>(N);
	for (int i = 0; i < N; i++) cin >> grid[i];
	vis.assign(N, vi(M, false));
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((!vis[i][j]) && grid[i][j] == '.') {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
