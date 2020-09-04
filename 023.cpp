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
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, X, cur;
	cin >> N >> X;
	vpii nums(N);
	for (int k = 0; k < N; k++) {
		cin >> nums[k].first;
		nums[k].second = k+1;
	}
	sort(nums.begin(), nums.end());
	int i = 0, j = N-1;
	while(i < j) {
		cur = nums[i].first + nums[j].first;
		if (cur == X) {
			cout << nums[i].second << " " << nums[j].second << "\n";
			return 0;
		} else if (cur < X) i++;
		else j--;
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
