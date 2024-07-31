/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
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
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        vector<int> t;
        for (int j = i; j < n; j++) {
            t.push_back(v[j]);
            sum += v[j];
            if (sum <= 100) {
                ans++;
                for (auto it : t) cout << it << " "; cout << endl;
            }

        }
    }

    cout << "ANS " << ans << endl;


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