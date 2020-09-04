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
	int X, N;
	vi lights;
	cin >> X >> N;
	lights = vi(N);
	set<int> L;
	for (int i = 0; i < N; i++) {
		cin >> lights[i];
		L.insert(lights[i]);
	}
	int rec=0, cur1, cur2, nxt=0, lst=0;
	set<int>::iterator it;
	it = L.begin();
	cur1 = 0;
	while(it != L.end()) {
		rec = max(rec, *it - cur1);
		cur1 = *it;
		it++;
	}
	vi ans;
	for (int i = N-1; i >= 0; i--) {
		rec = max(rec, max(*L.begin(), X - (*L.rbegin())));
		it = L.find(lights[i]);
		if (lst == i+1) rec = max(rec, nxt);
		if (it != L.begin() && *it != (*L.rbegin())) {
			it++;
			cur1 = *it;
			it--;
			it--;
			cur2 = *it;
			it++;
			nxt = cur1-cur2;
			lst = i;
		}
		ans.pb(rec);
		L.erase(it);
	}
	for (int i = N-1; i >= 0; i--) cout << ans[i] << "\n";
	return 0;
}
