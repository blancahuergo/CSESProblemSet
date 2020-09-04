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
	int N, X, cur, needed;
	cin >> N >> X;
	vpii A(N, pii());
	for (int i = 0; i < N; i++) {
		cin >> cur;
		A[i] = mp(cur, i);
	}
	sort(A.begin(), A.end());
	int j, k;
	for (int i = 0; i < N; i++) {
		for (int l = N-1; l > i; l--) {
			cur = A[i].f+A[l].f;
			needed = X-cur;
			if (needed <= 0) continue;
			j = i+1;
			k = l-1;
			while(j < k) {
				if (A[j].f+A[k].f == needed) {
					cout << A[i].s+1 << " " << A[j].s+1 << " " << A[k].s+1 << " " << A[l].s+1 << "\n";
					return 0;
				} else if (A[j].f + A[k].f < needed) j++;
				else k--;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
