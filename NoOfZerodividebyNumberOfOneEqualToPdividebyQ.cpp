/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


void Function() {

	int n , p , q;
	cin >> n >> p >> q;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (auto it : v) cout << it << " "; cout << endl;

	// replace 0 with -q and 1 with p and count the number of subarry with sum > 0

	for (int i = 0; i < n; i++) {
		if (v[i] == 0) v[i] = -q;
		else v[i] = p;
	}

	for (auto it : v) cout << it << " "; cout << endl;

	unordered_map<int, int> mp;
	mp[0] = 1;
	int sum = 0;
	int ans = 0;
	for (auto it : v) {
		sum += it;
		if (mp.find(sum) != mp.end()) {
			ans += mp[sum];
		}
		mp[sum] += 1;
	}
	cout << "Ans " << ans << endl;

}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input
	freopen("input1.txt", "r", stdin);
	// for writing output
	freopen("output1.txt", "w", stdout);
#endif

	int t = 1;
// cin >>t;

	while (t--) {
		Function();
	}

}