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
 
const int buckSize = 1000, numBuck = 1e9/buckSize;
int N, sal[200000], seg[4*numBuck], freq[numBuck];
map<int, map<int, int>> buck;
 
int bucket(int A) {
	if (A%buckSize == 0) return A/buckSize - 1;
	else return A/buckSize;
}
 
void makeTree(int x, int l, int r) {
	if (l == r) seg[x] = freq[l];
	else {
		int mid = l + (r-l)/2;
		makeTree(2*x, l, mid);
		makeTree(2*x+1, mid+1, r);
		seg[x] = seg[2*x]+seg[2*x+1];
	}
}
 
void init() {
	memset(freq, 0, sizeof(freq));
	int b;
	for (int i = 0; i < N; i++) {
		b = bucket(sal[i]);
		freq[b]++;
		if (sal[i] % buckSize != 0) buck[b][sal[i]%buckSize]++;
		else buck[b][buckSize]++;
	}
	makeTree(1, 0, numBuck-1);
}
 
int query(int x, int l, int r, int initInd, int endInd) {
	if (l > endInd || r < initInd) return -1;
	if (l >= initInd && r <= endInd) return seg[x];
	else {
		int mid = l + (r-l)/2;
		int left = query(2*x, l, mid, initInd, endInd);
		int right = query(2*x+1, mid+1, r, initInd, endInd);
		if (left == -1) return right;
		else if (right == -1) return left;
		else return left+right;
	}
}
 
int findLo(int B, int lo) {
	if (buck.find(B) == buck.end() || lo > buck[B].rbegin()->first) return 0;
	auto it = buck[B].lower_bound(lo);
	int ans = 0;
	while(it != buck[B].end()) {
		ans += it->second;
		it++;
	}
	return ans;
}
 
int findHi(int B, int hi) {
	if (buck.find(B) == buck.end() || hi < buck[B].begin()->first) return 0;
	auto it = buck[B].lower_bound(hi);
	if (it->first > hi) it--;
	int ans = 0;
	while(it != buck[B].begin()) {
		ans += it->second;
		it--;
	}
	return ans + buck[B].begin()->second;
}
 
int findMid(int B, int lo, int hi) {
	if (buck.find(B) == buck.end() || lo > buck[B].rbegin()->first) return 0;
	auto it = buck[B].lower_bound(lo);
	int ans = 0;
	while(it != buck[B].end() && it->first <= hi) {
		ans += it->second;
		it++;
	}
	return ans;
}
 
int querySal(int lo, int hi) {
	int posA = bucket(lo), posB = bucket(hi), numA, numB;
	if (lo % buckSize != 0) numA = lo % buckSize;
	else numA = buckSize;
	if (hi % buckSize != 0) numB = hi % buckSize;
	else numB = buckSize;
	if (posA == posB) return findMid(posA, numA, numB);
	else if (posA == posB-1) return findLo(posA, numA) + findHi(posB, numB);
	else return query(1, 0, numBuck-1, posA+1, posB-1) + findLo(posA, numA) + findHi(posB, numB);
}
 
void update(int x, int l, int r, int ind1, int ind2) {
	if (l > ind2 || r < ind1) return;
	if (l > ind1 && r < ind2) return;
	if (l == r) seg[x] = freq[l];
	else {
		int mid = l + (r-l)/2;
		update(2*x, l, mid, ind1, ind2);
		update(2*x+1, mid+1, r, ind1, ind2);
		seg[x] = seg[2*x]+seg[2*x+1];
	}
}
 
void updateSal(int pos, int newSal) {
	int numA, numB, posA = bucket(sal[pos]), posB = bucket(newSal);
	if (sal[pos] % buckSize == 0) numA = buckSize;
	else numA = sal[pos]%buckSize;
	if (newSal % buckSize == 0) numB = buckSize;
	else numB = newSal % buckSize;
	if (posA == posB) {
		buck[posA][numA]--;
		buck[posA][numB]++;
		sal[pos] = newSal;
		return;
	}
	freq[posA]--;
	freq[posB]++;
	buck[posA][numA]--;
	buck[posB][numB]++;
	sal[pos] = newSal;
	if (posA > posB) swap(posA, posB);
	update(1, 0, numBuck-1, posA, posB);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, a, b;
	char c;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> sal[i];
	init();
	while(Q--) {
		cin >> c >> a >> b;
		if (c == '?') cout << querySal(a, b) << "\n";
		else updateSal(a-1, b);
	}
	return 0;
}
