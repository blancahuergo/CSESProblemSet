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
 
ll mod = 1e9+7;
 
ll expo(ll a, ll b, ll c) {
	if (b == 0) return 1;
	ll res = expo(a, b/2, c);
	if (b & 1) return ((res*res % c)*a) % c;
	else return (res*res) % c;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	ll a, b, c;
	cin >> T;
	while(T--) {
		cin >> a >> b >> c;
		cout << expo(a, expo(b, c, mod-1), mod) << "\n";
	}
	return 0;
}
