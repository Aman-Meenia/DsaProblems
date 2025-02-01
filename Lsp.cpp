#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class cmp {

public:
  bool operator()(int a, int b) { return a < b; }
};

void fun(vector<int> &v) {
  int n = v.size();

  sort(v.begin(), v.end());

  for (auto it : v)
    cout << it << " ";
  cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  // for getting input
  freopen("input1.txt", "r", stdin);
  // for writing output
  freopen("output1.txt", "w", stdout);
#endif

  int n;
  cin >> n;
  cout << " n is " << n << endl;
  cout << " Aman Meeni " << endl;
}
