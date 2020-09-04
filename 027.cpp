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
	vi towers;
	cin >> N;
	int cur;
	while(N--) {
		cin >> cur;
		int lo = 0, hi = towers.size()-1, mid, ans = -1;
		while(lo <= hi) {
			mid = lo + (hi-lo)/2;
			if (towers[mid] > cur) {
				ans = mid;
				hi = mid-1;
			} else lo = mid+1;
		}
		if (ans == -1) towers.pb(cur);
		else towers[ans] = cur;
	}
	cout << towers.size();
	return 0;
}
