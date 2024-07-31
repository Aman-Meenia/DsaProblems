#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;

//  use to detect -ve cycle and to find minimum distance from source to all nodes
//  TIME COMPLECITY => O(N*E) -> E : No of Edges


vector<ll> bellman_ford(vector<vector<int>> &v , int root , int n ){

vector<ll> dp(n+1,LLONG_MAX);

dp[root]=0;
for(int k=0; k<n-1; k++){
	for(int i=0; i<v.size(); i++){
		int a = v[i][0];
		int b = v[i][1];
		int dis = v[i][2];
        ll t = dis+dp[a];
        if(dp[a]==LLONG_MAX) continue;
		dp[b]=min(dp[b],t);

	}
}

for(int i=0; i<v.size(); i++){
		int a = v[i][0];
		int b = v[i][1];
		int dis = v[i][2];
        ll t = dis+dp[a];
        if(t<dp[b]) return {-1};
		dp[b]=min(dp[b],t);

	}
return dp;


}




int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif




}
