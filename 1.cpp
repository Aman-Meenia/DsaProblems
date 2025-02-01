/*
 Author: Aman Meenia
 Created: Sun Sep  8 19:55:43 IST 2024
 */
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

void Function() {

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  set<int> st;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    set<int> newSt;
    for (auto it : st) {
      newSt.insert(it & v[i]);
    }
    newSt.insert(v[i]);

    for (auto it : newSt) {
      ans = max(ans, it);
    }

    st = newSt;
  }
  cout << ans << endl;
}

int main() {

  int t = 1;

  while (t--) {
    Function();
  }
}
