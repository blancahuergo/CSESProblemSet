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
 
vvi table;
vi nums, logs;
int N;
 
void precomputation() {
	int height = (int) ceil(log2((double) N));
	logs.assign(N+1, 0);
	for (int i = 2; i <= N; i++) logs[i] = logs[i/2]+1;
	table.assign(N, vi(height+1));
	for (int i = 0; i < N; i++) table[i][0] = nums[i];
	for (int j = 1; j <= height; j++) {
		for (int i = 0; i + (1<<j) <= N; i++) {
			table[i][j] = min(table[i][j-1], table[i + (1<<(j-1))][j-1]);
		}
	}
}
 
int RMQ(int l, int r) {
	int j = logs[r-l+1];
	return min(table[l][j], table[r-(1<<j)+1][j]);
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, a, b;
	cin >> N >> Q;
	nums.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> nums[i];
	precomputation();
	while(Q--) {
		cin >> a >> b;
		cout << RMQ(a-1, b-1) << "\n";
	}
	return 0;
}
