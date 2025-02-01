/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int Ans = 0;

void merge(vector<int> & v , int low , int mid , int high) {

	int i = low;
	int j = mid + 1;
	int k = low;
	vector<int> t(high + 1);

	while (i <= mid && j <= high) {
		if (v[i] < v[j]) {
			t[k++] = v[i++];
		} else {
			Ans += (mid - i + 1);
			t[k++] = v[j++];
		}
	}

	while (i <= mid) {
		t[k++] = v[i++];
	}

	while (j <= high) {
		t[k++] = v[j];
	}

	for (int it = low; it <= high; it++) {
		v[it] = t[it];
	}


}




#define mid low + (high-low)/2

void mergesort(vector<int> & v , int low , int high) {
	if (low >= high) return ;

	mergesort(v, low, mid);
	mergesort(v, mid + 1, high);
	merge(v, low, mid, high);
}




void Function() {

	int n , p , q;
	cin >> n >> p >> q;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	// count the number of subarray with no. of zero/no of one > p/q
	// no. of zero (q) > no. of one (p)
	//  no. of zer (q) - no. of one(p) > 0;
	// count the number of subarray with sum > 0
	// no. of subarry - number of subarray with sum <=0 (inversion count)



	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			v[i] = q;
		} else {
			v[i] = -p;
		}
	}


	vector<int> pre;
	pre.push_back(0);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		pre.push_back(sum);
	}

	// for (auto it : pre) cout << it << " "; cout << endl;
	mergesort(pre, 0, n);
	// for (auto it : pre) cout << it << " "; cout << endl;


	ll totalWays = n * (n + 1) / 2;

	// cout << totalWays << endl;
	cout << " totalWays " << totalWays - Ans << endl;
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