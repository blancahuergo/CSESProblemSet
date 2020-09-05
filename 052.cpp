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
	int N, M;
	string A, B;
	cin >> A >> B;
	N = (int) A.length();
	M = (int) B.length();
	vvi DP;
	DP.assign(N+1, vi(M+1, 0));
	for (int i = 1; i <= N; i++) DP[i][0] = i;
	for (int j = 1; j <= M; j++) DP[0][j] = j;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (A[i-1] == B[j-1]) DP[i][j] = DP[i-1][j-1];
			else DP[i][j] = 1 + min(DP[i-1][j], min(DP[i][j-1], DP[i-1][j-1]));
		}
	}
	cout << DP[N][M];
	return 0;
}
