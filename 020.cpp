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
	int N, M, cur;
	multiset<int> tick;
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		cin >> cur;
		tick.insert(cur);
	}
	multiset<int>::iterator it;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		if (tick.empty()) {
			cout << "-1\n";
			continue;
		}
		if (*(tick.rbegin()) < cur) {
			it = tick.end();
			it--;
			cout << *(tick.rbegin()) << "\n";
			tick.erase(it);
			continue;
		}
		if (*(tick.begin()) > cur) {
			cout << "-1\n";
			continue;
		}
		it = tick.lower_bound(cur);
		if (*it > cur) it--;
		if (*it > cur) cout << "-1\n";
		else {
			cout << *it << "\n";
			tick.erase(it);
		}
	}
	return 0;
}
