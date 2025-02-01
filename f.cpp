/*
 Author: Aman Meenia
 Created: Thu Dec 12 22:01:14 IST 2024
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

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  int ans = 0;
  for (auto it : v) {
    ans = ans ^ it;
  }

  if (ans == 0) {
    cout << "YES" << '\n';
    return;
  }

  int temp_ans = 0;
  int cnt = 0;
  for (auto it : v) {
    temp_ans = temp_ans ^ it;
    if (temp_ans == ans) {
      cnt++;
      temp_ans = 0;
    }
  }

  if (cnt >= 2) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << '\n';
  }
}

// <------------------------------ END CODE ----------------------->

int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    Function();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
