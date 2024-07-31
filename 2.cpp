/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


void minOperations(string & s) {
	int n = s.size();

	int cnt = 0;
	char pre = s[0];
	int operation = 0;
	for (int i = 0; i < n; i++) {


		if (pre == s[i]) {
			cnt++;
		} else {
			if (cnt >= 2) {
				operation += (cnt - 1);
			}
			pre = s[i];
			cnt = 1;
		}
	}
	if (cnt >= 2) {
		operation += (cnt - 1);

	}


	operation += 1;

	cout << operation / 2 << endl;


}


void Function() {

	string s;
	cin >> s;


	minOperations(s);


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