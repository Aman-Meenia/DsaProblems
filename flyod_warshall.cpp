#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;




// void flyod_warshall(vector<vector<int>> & dp){
// int n = dp.size();
// 	for(int k=1; k<=n; k++){
// 		for(int i=1; i<=n; i++){
// 			for(int j=1; j<=n; j++){
// dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
// 			}
// 		}
// 	}


// }


void flyod_warshall(vector<vector<int>> & dp){
int n = dp.size();
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}


}




int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

int n;
cin >> n;
vector<vector<int>> v(n,vector<int>(n,0));
for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
		cin>>v[i][j];
		if(v[i][j]==-1) v[i][j]=1e9;
	}
}

flyod_warshall(v);
for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
	cout<<v[i][j]<<" ";
	}cout<<endl;
}cout<<endl;


}
