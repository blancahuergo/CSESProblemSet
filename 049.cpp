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
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vvi grid;
	int N, mod = 1e9 + 7;
	cin >> N;
	grid.assign(N, vi(N, 0));
	string S;
	cin >> S;
	if (S[0] == '*') cout << "0";
	else {
		grid[0][0] = 1;
		for (int j = 1; j < N; j++) if (S[j] != '*') grid[0][j] = grid[0][j-1];
		for (int i = 1; i < N; i++) {
			cin >> S;
			if (S[0] != '*') grid[i][0] = grid[i-1][0];
			for (int j = 1; j < N; j++) if (S[j] != '*') grid[i][j] = (grid[i-1][j]+grid[i][j-1])%mod;
		}
		cout << grid[N-1][N-1];
	}
	return 0;
}
