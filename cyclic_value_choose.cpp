#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;


int n ,m;
vector<int> temp;
int dp[110][110];
ll fun(string & s , string & t , int index , int i){

if(i>=m){
    return 0;
}


ll ans1=INT_MAX,ans2=INT_MAX ,ans=INT_MAX;

if(dp[index][i]!=-1) return dp[index][i];
for(int k=0; k<index; k++){
if(s[k]==t[i]){
 ans1= (index-k)+1+fun(s,t,k,i+1);
 ans2 = (k+2)+(n-index-1)+fun(s,t,k,i+1);
 ans =min(ans,ans1);

    ans = min(ans,ans2);

}
}

for(int k=index; k<n; k++){
if(s[k]==t[i]){

ans1 = index+(n-k+1)+fun(s,t,k,i+1);
     ans2 = k-index+1+fun(s,t,k,i+1);
    ans = min(ans,ans2);
    ans = min(ans,ans1);

}
}

return dp[index][i]=ans;

}


 
int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
// Leetcode 514. Freedom Trail


string s , t;
cin >> s >> t;

memset(dp,-1,sizeof dp);
n = s.size();
m = t.size();
// cout<<s<<" t "<<t<<endl;
int ans = fun(s,t,0,0);
cout<<" ans "<<ans<<endl;

 



}
