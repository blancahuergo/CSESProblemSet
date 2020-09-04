#include <iostream>
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
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, cur, rec;
	cin >> N;
	priority_queue<pair<int, bool>> PQ;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		PQ.push(mp(-cur, true));
		cin >> cur;
		PQ.push(mp(-cur, false));
	}
	cur = rec = 0;
	pair<int, bool> P;
	while(!PQ.empty()) {
		P = PQ.top();
		PQ.pop();
		if (P.second) {
			cur++;
			rec = max(rec, cur);
		}
		else cur--;
	}
	cout << rec << "\n";
	return 0;
}
