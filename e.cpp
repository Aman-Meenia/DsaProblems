/*
 Author: Aman Meenia
 Created: Thu Dec 12 22:01:14 IST 2024
 */
#include <bits/stdc++.h>
#include <queue>
#define int long long
#define ll long long
#define mod 1000000007
#define pb push_back
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// <------------------------------ START CODE --------------------->

void Function() {

  int n, k1, k2;
  cin >> n >> k1 >> k2;

  vector<int> v1(n);
  vector<int> v2(n);

  for (auto &it : v1)
    cin >> it;
  for (auto &it : v2)
    cin >> it;

  priority_queue<int> pq;

  for (int i = 0; i < n; i++) {
    int val = abs(v1[i] - v2[i]);
    if (val > 0)
      pq.push(val);
  }

  int k = k1 + k2;

  while (k > 0 && !pq.empty()) {
    int t = pq.top();
    pq.pop();
    t -= 1;
    if (t > 0)
      pq.push(t);
    k--;
  }

  if (pq.empty()) {
    if (k % 2 == 0)
      cout << "0" << '\n';
    else
      cout << "1" << '\n';
  } else {
    int ans = 0;
    while (!pq.empty()) {
      int t = pq.top();
      ans += t * t;
      pq.pop();
    }
    cout << ans << '\n';
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
