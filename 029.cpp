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
 
bool comp(vi A, vi B) {
	if (A[1] != B[1]) return A[1] < B[1];
	return A[0] > B[0];
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	vvi cust;
	cin >> N;
	cust.assign(N, vi(3));
	for (int i = 0; i < N; i++) {
		cin >> cust[i][0] >> cust[i][1];
		cust[i][2] = i;
	}
	sort(cust.begin(), cust.end(), comp);
	vi deci(N, 0);
	set<pii> rooms;
	set<pii>::iterator it;
	for (int i = 0; i < N; i++) {
		if (rooms.empty()) {
			rooms.insert(mp(cust[i][1], cust[i][2]));
			deci[cust[i][2]] = 1;
		}
		else if (cust[i][0] <= (*rooms.begin()).f) {
			rooms.insert(mp(cust[i][1], cust[i][2]));
			deci[cust[i][2]] = rooms.size();
		} else if (cust[i][0] > (*rooms.rbegin()).f) {
			it = rooms.end();
			it--;
			deci[cust[i][2]] = deci[(*it).s];
			rooms.erase(it);
			rooms.insert(mp(cust[i][1], cust[i][2]));
		}
		else {
			it = rooms.lower_bound(mp(cust[i][0], INT_MIN));
			it--;
			deci[cust[i][2]] = deci[(*it).s];
			rooms.erase(it);
			rooms.insert(mp(cust[i][1], cust[i][2]));
		}
	}
	cout << rooms.size() << "\n";
	for (int i = 0; i < N; i++) cout << deci[i] << " ";
	return 0;
}
