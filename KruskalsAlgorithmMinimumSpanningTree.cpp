#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N = 100010;

vector<int> Parent(N);
vector<int> Rank(N);


void build(int n) {
	for (int i = 0; i <= n; i++) {
		Parent[i] = i;
		Rank[i] = 0;
	}
}


int find_parent(int node) {
	if (Parent[node] == node) return node;
	return Parent[node] = find_parent(Parent[node]);
}


void union_find(int x , int y) {

	x = find_parent(x);
	y = find_parent(y);

	if (x == y) return ;

	if (x < y) swap(x, y);

	if (Rank[x] == Rank[y]) Rank[x] += 1;
	Parent[y] = x;


}



int main() {
#ifndef ONLINE_JUDGE
	// for getting input
	freopen("input1.txt", "r", stdin);
	// for writing output
	freopen("output1.txt", "w", stdout);
#endif

	int n , m;
	cin >> n >> m;

	vector<vector<int>> v;
	for (int i = 0; i < m; i++) {
		int a , b , c;
		cin >> a >> b >> c;
		a--, b--;
		v.push_back({c, a, b});

	}

	sort(v.begin(), v.end());
	ll ans = 0;
	build(n);

	for (int i = 0; i < v.size(); i++) {
		int weight = v[i][0];
		int x = v[i][1];
		int y = v[i][2];
		x = find_parent(x);
		y = find_parent(y);
		if (x == y) {
			continue;
		}
		ans += weight;
		union_find(x, y);


	}
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int parentis = find_parent(i);
		mp[parentis] += 1;
	}
	int maxi = 0;
	for (auto it : mp) {
		maxi = max(maxi, it.second);
	}
	if (maxi < n) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}



	cout << ans << endl;








}