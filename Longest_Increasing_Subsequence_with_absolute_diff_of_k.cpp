#include<bits/stdc++.h>
#define ll long long
using namespace std;





int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


int n ;
cin >> n;
vector<int> height(n);
vector<int> infront(n);

for(int i=0; i<n; i++){
cin >> height[i];
}

for(int i=0; i<n; i++){
    cin >> infront[i];
}


vector<vector<int>> v;

for(int i=0; i<n; i++){
    v.push_back({height[i],infront[i]});
}


sort(v.begin(),v.end());

vector<int> dp(n,1);
vector<int> ans(n);




for(int i=0; i<n; i++){
    int front = v[i][1];
int cnt = 0;
// cout<<" FRONT "<<front<<endl;
    for(int k=0; k<n; k++){
        if(dp[k]==1){
            cnt++;
        }

        if(cnt>front){

ans[k]=v[i][0];

dp[k]=0;
            break;
        }
    }
}


for(auto it:ans)cout<<it<<" ";cout<<endl;




}


