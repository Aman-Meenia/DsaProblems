/*
 Author: Aman Meenia
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

const int maxBit = 32;
int up[maxBit][100000];
void binary_lifting(vector<int> & v ) {

    int n = v.size();
// change accoring to question
    for (int i = 0; i < n; i++) {
        up[0][i] = v[i];
    }

    for (int j = 1; j < maxBit; j++) {

        for (int i = 0; i < n; i++) {
            if (up[j - 1][i] == -1) {
                up[j][i] = -1;
            } else {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }

        }

    }



}

int query_ans(int &node , int &k ) {


    for (int i = maxBit - 1; i >= 0; i--) {

        if (k & (1 << i)) {
            node = up[i][node];
            if (node == -1) return -1;
        }
    }
    return node;


}


void Function() {



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