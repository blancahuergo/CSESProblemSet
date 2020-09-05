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
	ll last[6], cur;
	int N;
	cin >> N;
	last[0] = 1;
	last[1] = 2;
	last[2] = 4;
	last[3] = 8;
	last[4] = 16;
	last[5] = 32;
	ll mod = 1e9 + 7;
	if (N <= 6) {
		cout << last[N-1];
	} else {
		for (int i = 7; i <= N; i++) {
			cur = last[0]+last[1]+last[2]+last[3]+last[4]+last[5];
			for (int i = 1; i < 6; i++) last[i-1] = last[i];
			last[5] = cur % mod;
		}
		cout << last[5];
	}
	return 0;
}
