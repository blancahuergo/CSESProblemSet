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
 
bool cmp(pii A, pii B) {
	if (A.s != B.s) return A.s < B.s;
	return A.f < B.f;
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K, st, end;
	cin >> N >> K;
	multiset<int> watching;
	multiset<int>::iterator it;
	vpii films(N);
	for (int i = 0; i < N; i++) {
		cin >> st >> end;
		films[i] = mp(st, end);
	}
	sort(films.begin(), films.end(), cmp);
	int tot = 1;
	watching.insert(films[0].s);
	for (int i = 1; i < N; i++) {
		if (*watching.rbegin() <= films[i].f) {
			it = watching.end();
			it--;
			watching.erase(it);
			watching.insert(films[i].s);
			tot++;
		} else if (*watching.begin() > films[i].f) {
			if ((int) watching.size() < K) {
				watching.insert(films[i].s);
				tot++;
			}
		}
		else {
			it = watching.lower_bound(films[i].f);
			if (*it != films[i].f) it--;
			watching.erase(it);
			watching.insert(films[i].s);
			tot++;
		}
	}
	cout << tot;
	return 0;
}
