/*
 Author: Aman Meenia
 Created: Sun Oct 13 14:22:44 IST 2024
 */
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define mod 1000000007
using namespace std;

void Function() {
  int n;
  cin >> n;

  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int k = 3;
  multiset<int> st1;
  multiset<int> st2;

  int low = 0;
  int high = 0;

  int mid = k / 2;

  if (k % 2 == 1) {
    mid += 1;
  }

  vector<int> ans;
  int size = v.size();
  while (high < size) {
    st1.insert(v[high]);

    if (st1.size() > mid) {
      st2.insert(*st1.rbegin());
      auto it = st1.find(*st1.rbegin());
      st1.erase(it);
    }

    if (!st2.empty()) {
      // check if the first value of second set is greater than the last value
      // of first set
      int st1val = *st1.rbegin();
      int st2val = *st2.begin();

      if (st1val > st2val) {
        auto it = st1.find(st1val);
        st1.erase(it);

        it = st2.find(st2val);
        st2.erase(it);

        st1.insert(st2val);
        st2.insert(st1val);
      }
    }

    if (high - low + 1 == k) {
      // for (auto it : st1)
      //   cout << it << " ";
      // cout << endl;
      // for (auto it : st2)
      //   cout << it << " ";
      // cout << endl;

      if (k % 2 == 0) {
        int val = *st1.rbegin();
        val += *st2.begin();
      } else {
        int val = *st1.rbegin();
        ans.push_back(val);
      }

      // Now we have to remove the last element from the array

      if (st1.find(v[low]) != st1.end()) {
        auto it = st1.find(v[low]);
        st1.erase(it);
      } else {
        auto it = st2.find(v[low]);
        st2.erase(it);
      }
      low++;
    }
    high++;
  }

  for (auto it : ans)
    cout << it << " ";
  cout << endl;
}

int main() {

  int t = 1;
  // cin >>t

  while (t--) {
    Function();
  }
}
