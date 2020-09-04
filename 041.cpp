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
	int N, K;
	ll bigSum, smallSum, ans;
	multiset<int> small, big;
	multiset<int>::iterator it;
	cin >> N >> K;
	int A[N];
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < K; i++) big.insert(A[i]);
	while (big.size() > small.size()) {
		small.insert(*big.begin());
		big.erase(big.begin());
	}
	bigSum = smallSum = 0ll;
	for (it = small.begin(); it != small.end(); it++) smallSum += *it;
	for (it = big.begin(); it != big.end(); it++) bigSum += *it;
	ans = bigSum - smallSum;
	if (K & 1) ans += *small.rbegin();
	cout << ans << "\n";
	for (int i = K; i < N; i++) {
		if (big.empty() || (*big.begin() > A[i-K])) {
			small.erase(small.find(A[i-K]));
			smallSum -= A[i-K];
		}
		else {
			big.erase(big.find(A[i-K]));
			bigSum -= A[i-K];
		}
		while(big.size() > small.size()) {
			small.insert(*big.begin());
			smallSum += *big.begin();
			bigSum -= *big.begin();
			big.erase(big.begin());
		}
		if (small.empty() || A[i] <= *small.rbegin()) {
			small.insert(A[i]);
			smallSum += A[i];
		}
		else {
			big.insert(A[i]);
			bigSum += A[i];
		}
		while(big.size() > small.size()) {
			small.insert(*big.begin());
			smallSum += *big.begin();
			bigSum -= *big.begin();
			big.erase(big.begin());
		}
		while(small.size() - big.size() > 1) {
			big.insert(*small.rbegin());
			bigSum += *small.rbegin();
			smallSum -= *small.rbegin();
			it = small.end();
			it--;
			small.erase(it);
		}
		ans = bigSum - smallSum;
		if (K & 1) ans += *small.rbegin();
		cout << ans << "\n";
	}
	return 0;
}
