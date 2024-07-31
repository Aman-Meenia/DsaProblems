/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 4
using namespace std;

template <typename T> void _print(vector<T> v) { for (auto it : v) { cout << it << " "; } cout << endl; }

template <typename T> void _print(vector<vector<T>> v) { for (auto it : v) { for (auto a : it) { cout << a << " "; } cout << endl; } }

template <typename T, typename T2> void _print(map<T, T2> mp) { for (auto it : mp) { cout << it.first << " " << it.second << endl; } }

template <typename T, typename T2> void _print(unordered_map<T, T2> mp) { for (auto it : mp) { cout << it.first << " " << it.second << endl; } }

template <typename T> void _print(set<T> st) { for (auto it : st) { cout << it << " "; } cout << endl; }

template <typename T> void _print(unordered_set<T> st) { for (auto it : st) { cout << it << " "; } cout << endl; }

template <typename T> void _print(multiset<T> st) { for (auto it : st) { cout << it << " "; } cout << endl; }

template <typename T, typename T2> void _print(vector<pair<T, T2>> v) { for (auto it : v) { cout << it.first << " " << it.second << endl; } }

template <typename T, typename T2> void _print(T2 n, vector<T> adj[]) { for (int i = 0; i < n; i++) { cout << i << " : "; for (auto it : adj[i]) { cout << it << " "; } cout << endl; } }

template <typename T, typename T1> void _print(T n, vector<vector<T1>> adj[]) { for (int i = 0; i < n; i++) { cout << i << " : "; for (const auto& it : adj[i]) { cout << "["; for (size_t j = 0; j < it.size(); ++j) { cout << it[j] << (j < it.size() - 1 ? "," : ""); } cout << "] "; } cout << "\n"; } }

template <typename T> void _print(T n, vector<pair<int, int>> adj[]) { for (int i = 0; i < n; i++) { cout << i << " : "; for (const auto& p : adj[i]) { cout << "[" << p.first << "," << p.second << "] "; } cout << "\n"; } }

template <typename T , typename T1 , typename T2 , typename T3 , typename T4 > void _print(T a , T1 b , T2 c , T3 d , T4 e) { cout << a << " # " << b << " # " << c << " # " << d << " # " << e << endl;}

template <typename T , typename T1 , typename T2 , typename T3 > void _print(T a, T1 b , T2 c , T3 d) { cout << a << " # " << b << " # " << c << " # " << d << endl;}

template <typename T , typename T1 , typename T2 > void _print(T a , T1 b , T2 c) { cout << a << " # " << b << " # " << c << endl;}

template <typename T , typename T1 > void _print(T a, T1 b) { cout << a << " # " << b << endl;}

template <typename T > void _print(T a) { cout << a << endl;}


// int arr1[4] = {0, -1, 0, 1};
// int arr2[4] = {1, 0, -1, 0};

int arr1[4] = {1, 0, -1, 0};
int arr2[4] = {0, 1, 0, -1};

const int n = 9 , m = 9;
int targetX , targetY;


bool check(int x , int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) {
		return true;
	}
	return false;
}

bool pathFound(int x , int y) {
	if (x == targetX && y == targetY) {
		return true;
	}
	return false;
}

string generateOutputString(int x , int y, bool left) {
	x += 1, y += 1;
	string a = to_string(x);
	string b = to_string(y);
	if (left == true) {
		string ans = "Kill (" + b + "," + a + "). Turn Left";
		return ans;
	} else {
		string ans = "Jump (" + b + "," + a + ").";
		return ans;
	}
}



vector<vector<string>> Ans;

vector<string> t;

bool generateDiffPaths(vector<vector<char>> & v , int startX , int startY , int cnd) {

	// next move
	int x = startX + arr1[cnd];
	int y = startY + arr2[cnd];

	// check move possible
	if (!check( x , y)) return false;

	// if path found simply return
	if (pathFound(x, y)) {
		string a = to_string(x + 1);
		string b = to_string(y + 1);
		string arriveString = "Arrive (" + b + "," + a + ")";
		t.push_back(arriveString);
		Ans.push_back(t);
		t.pop_back();
		return true;
	} else {

		if (v[x][y] == 'S') {
			// case1-> Move left
			string temp = generateOutputString(x, y, true);
			t.push_back(temp);
			generateDiffPaths(v, x, y, (cnd + 1) % mod);
			t.pop_back();
			// case2->  follow same path
			temp = generateOutputString(x, y, false);
			t.push_back(temp);
			generateDiffPaths(v, x, y, cnd);
			t.pop_back();
		} else {
			generateDiffPaths(v, x, y, cnd);
		}

	}




	return true;



}


void Function() {


	vector<vector<char>> v(n, vector<char>(m, '.'));

	int different_soldiers;
	cin >> different_soldiers;

	for (int i = 0; i < different_soldiers; i++) {
		int x , y;
		cin >> x >> y;
		// also check if the path provided by user is lies in board or not
		x--, y--;
		if (!check(y, x)) {
			cout << "Enter the values between (1,1) and  (9,9)" << endl;
			return ;
		}

		v[y][x] = 'S';
	}

	int x , y ;
	cin >> x >> y;
	x-- , y--;
	if (!check(y, x)) {
		cout << "Enter the values between (1,1) and  (9,9)" << endl;
		return ;
	}

	targetX = y;
	targetY = x;
	v[y][x] = 'C';

	// _print(v);

	generateDiffPaths(v, y, x, 0);

	int index = 0;

	if (Ans.size() > 0) {
		cout << "There are " << Ans.size() << " unique paths for your ‘special_castle’ " << endl;
	} else {
		cout << " There is no  path for your ‘special_castle’" << endl;

	}
	for (auto it : Ans) {
		cout << "Path " << index + 1 << ":" << endl;
		cout << "=======" << endl;
		cout << "Start:(" << x + 1 << "," << y + 1 << ")" << endl;

		for (auto a : it) {
			cout << a << endl;
		}
		index++;
	}


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


// TestCase1:
// 11
// 1 1
// 8 9
// 1 9
// 4 1
// 4 2
// 4 8
// 2 6
// 5 6
// 8 2
// 5 9
// 2 8
// 1 2

// Output1:
// There are 3 unique paths for your ‘special_castle’
// Path 1:
// =======
// Start:(1,2)
// Kill (1,9). Turn Left
// Kill (5,9). Turn Left
// Kill (5,6). Turn Left
// Kill (2,6). Turn Left
// Kill (2,8). Turn Left
// Kill (4,8). Turn Left
// Kill (4,2). Turn Left
// Arrive (1,2)
// Path 1:
// =======
// Start:(1,2)
// Kill (1,9). Turn Left
// Kill (5,9). Turn Left
// Kill (5,6). Turn Left
// Kill (2,6). Turn Left
// Kill (2,8). Turn Left
// Kill (4,8). Turn Left
// Jump (4,2).
// Kill (4,1). Turn Left
// Kill (1,1). Turn Left
// Arrive (1,2)
// Path 1:
// =======
// Start:(1,2)
// Kill (1,9). Turn Left
// Jump (5,9).
// Kill (8,9). Turn Left
// Kill (8,2). Turn Left
// Jump (4,2).
// Arrive (1,2)
