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

const int N = 100001;

void Function() {
  int n;
  cin >> n;
  vector<int> v(N, 0);
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    v[val] += val;
  }

  vector<int> dp(N);
  dp[0] = 0;
  dp[1] = v[1];
  int ans = 0;
  for (int i = 2; i < N; i++) {
    dp[i] = v[i] + dp[i - 2];
    dp[i] = max(dp[i], dp[i - 1]);
    ans = max(ans, dp[i]);
  }

  cout << ans << '\n';
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
