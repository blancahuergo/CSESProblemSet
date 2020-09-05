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
	int N;
	cin >> N;
	int C[N], sum = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> C[i];
		sum += C[i];
	}
	vi DP = vi(sum+1, 0);
	DP[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = sum; j >= C[i]; j--) {
			if (DP[j] == 0 && DP[j - C[i]] == 1) {
				DP[j] = 1;
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	for (int i = 1; i <= sum; i++) if (DP[i]) cout << i << " ";
	return 0;
}
