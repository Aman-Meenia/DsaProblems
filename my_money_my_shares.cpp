/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
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

int totalWeight = 0;

double bestPossible(int a , int b , int c) {


	double A = (double)a / totalWeight;
	double B = (double)b / totalWeight;
	double C = (double)c / totalWeight;

	double expectedA = (double)50 / 100;
	double expectedB = (double)30 / 100;
	double expectedC = (double)20 / 100;

	// _print(A, B, C);
	// _print(expectedA, expectedB, expectedC);
	double score = abs(A - expectedA);
	score += abs(B - expectedB);
	score += abs(C - expectedC);

	return score;
}

vector<vector<int>> tempAns(3);
vector<vector<int> > ans;
double score = INT_MAX;

void differentWays(vector<int> & weight , int index , int a , int b , int c) {

	if (index >= weight.size()) {
		double tempScore = bestPossible(a, b, c);
		if (tempScore < score) {
			score = tempScore;
			ans = tempAns;
		}

		return;
	}

// for some optimization because we cannot get the best possible answer than this
	if (score == 0) {
		return;
	}
	// choose a
	tempAns[0].push_back(weight[index]);
	differentWays(weight, index + 1, a + weight[index], b, c);
	tempAns[0].pop_back();

	// choose b
	tempAns[1].push_back(weight[index]);
	differentWays(weight, index + 1, a, b + weight[index], c);
	tempAns[1].pop_back();
	// choose c
	tempAns[2].push_back(weight[index]);
	differentWays(weight, index + 1, a, b, c + weight[index]);
	tempAns[2].pop_back();


}



void Function() {

	vector<int> weight;
	while (true) {
		int wt;
		cin >> wt;
		if (wt == -1) break;
		weight.push_back(wt);
	}


	// _print(weight);
	totalWeight = 0;
	for (auto it : weight) {
		totalWeight += it;
	}

	differentWays(weight, 0, 0, 0, 0);

	int index = 0;
	for (auto it : ans) {
		if (index == 0) {
			cout << "Ram: ";
		} else if (index == 1) {
			cout << "Sham: ";
		} else {
			cout << "Rahim: ";
		}
		for (auto a : it) {
			cout << a << " ";
		} cout << endl;
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



// Input1
// 400
// 100
// 400
// 300
// 200
// 300
// 100
// 200
// -1

// Ouput1
// Ram: 400 100 400 100
// Sham: 300 300
// Rahim: 200 200


