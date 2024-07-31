#include<bits/stdc++.h>
#define ll long long

using namespace std;



vector<int> prefix_function(string & s){
int n = s.size();

vector<int> dp(n,0);

int j=0;
for(int i=1; i<n; i++){

while(j>0 && s[i]!=s[j]){
	j=dp[j-1];
}

if(s[i]==s[j]){
	j++;
}

dp[i]=j;

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


string  s ,t;
cin >> s >> t;


string tt = t+"H"+s;

vector<int> dp = prefix_function(tt);

int ans =0;

for(int i=0; i<dp.size(); i++){
	if(dp[i]==t.size()){
		ans+=1;
	}
}

cout<<ans<<endl;










}