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
#define fir first
#define sec second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()

vvi DPPlayer, DPMonst, pre;
int grid[1000][1000];
int R, C, startR, startC, len;
string S;
vector<array<int, 2>> monst;

void pathBack(int curR, int curC) {
	int val = pre[curR][curC];
	if (val == -1) {
		cout << len << "\n";
		return;
	}
	len++;
	if (val <= 2) {
		if (val == 1) {
			pathBack(curR+1, curC);
			S.push_back('U');
		} else {
			pathBack(curR, curC+1);
			S.push_back('L');
		}
	} else {
		if (val == 3) {
			pathBack(curR-1, curC);
			S.push_back('D');
		} else {
			pathBack(curR, curC-1);
			S.push_back('R');
		}
	}
}

void solve() {
	DPMonst.assign(R, vi(C, INT_MAX));
	queue<int> rows, cols;
	int curR, curC, newR, newC;
	int diffR[4] = {0, 0, -1, 1}, diffC[4] = {-1, 1, 0, 0};
	for (int i = 0; i < (int) monst.size(); i++) {
		rows.push(monst[i][0]);
		cols.push(monst[i][1]);
		DPMonst[monst[i][0]][monst[i][1]] = 0;
	}
	while(rows.size()) {
		curR = rows.front();
		rows.pop();
		curC = cols.front();
		cols.pop();
		for (int j = 0; j < 4; j++) {
			newR = curR + diffR[j];
			if (newR < 0 || newR == R) continue;
			newC = curC + diffC[j];
			if (newC < 0 || newC == C) continue;
			if (grid[newR][newC] && DPMonst[newR][newC] > DPMonst[curR][curC]+1) {
				DPMonst[newR][newC] = DPMonst[curR][curC]+1;
				rows.push(newR);
				cols.push(newC);
			}
		}
	}
	DPPlayer.assign(R, vi(C, INT_MAX));
	pre.assign(R, vi(C, -1));
	DPPlayer[startR][startC] = 0;
	rows.push(startR);
	cols.push(startC);
	while(rows.size()) {
		curR = rows.front();
		rows.pop();
		curC = cols.front();
		cols.pop();
		if (curR == 0 || curR == R-1 || curC == 0 || curC == C-1) {
			cout << "YES\n";
			pathBack(curR, curC);
			cout << S;
			return;
		}
		for (int j = 0; j < 4; j++) {
			newR = curR + diffR[j];
			if (newR < 0 || newR == R) continue;
			newC = curC + diffC[j];
			if (newC < 0 || newC == C) continue;
			if (grid[newR][newC] && DPPlayer[newR][newC] > DPPlayer[curR][curC]+1 && DPMonst[newR][newC] > DPPlayer[curR][curC]+1) {
				DPPlayer[newR][newC] = DPPlayer[curR][curC]+1;
				rows.push(newR);
				cols.push(newC);
				if (diffR[j] != 0) {
					if (diffR[j] == 1) pre[newR][newC] = 3;
					else pre[newR][newC] = 1;
				} else {
					if (diffC[j] == 1) pre[newR][newC] = 4;
					else pre[newR][newC] = 2;
				}
			}
		}
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C;
	char c;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> c;
			if (c == '.') {
				grid[i][j] = 1;
				continue;
			}
			grid[i][j] = 0;
			if (c == '#') continue;
			else if (c == 'A') {
				startR = i;
				startC = j;
			} else monst.pb({i, j});
		}
	}
	solve();
	return 0;
}
