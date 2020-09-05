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
 
vi nums;
int N;
 
int gcdMax(int highest) {
	vi countArr;
	countArr.assign(highest+1, 0);
	for(int i = 0; i < N; i++) countArr[nums[i]]++;
	int countMul, j;
	for (int i = highest; i >= 1; i--) {
		j = i;
		countMul = 0;
		while (j <= highest) {
			if (countArr[j] > 0) {
				if (countArr[j] >= 2) return j;
				else countMul++;
			}
			j += i;
			if (countMul >= 2) return i;
		}
	}
	return 0;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	nums = vi(N);
	int h = 0;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		h = max(h, nums[i]);
	}
	cout << gcdMax(h);
	return 0;
}
