/*
 Author: Aman Meenia
 Created: Fri Jan 31 22:18:03 IST 2025
 */
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define mod 1000000007
#define pb push_back
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// <------------------------------ START CODE --------------------->

void Function() {

  int n;
  cin >> n;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({1, 2});
  pq.push({1, 1});
  pq.push({1, 4});
  pq.push({0, -1});
  pq.push({12, 12});

  while (!pq.empty()) {
    cout << pq.top().first << " $ " << pq.top().second << endl;
    pq.pop();
  }
}

// <------------------------------ END CODE ----------------------->

int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  while (t--) {
    Function();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
