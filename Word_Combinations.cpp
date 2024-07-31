#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

unordered_set<string> st;
int n;
int dp[5010];
ll fun(string &s , int index){


if(index>=n){
	return 1;
}

if(dp[index]!=-1) return dp[index];
int ans = 0;
string t;
for(int i=index; i<n; i++){
t.push_back(s[i]);

if(st.find(t)!=st.end()){
ans= ans%mod +fun(s,i+1)%mod;
}
}



return ans%mod;


}



int main(){

	#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

    string s;
    cin >> s;

int k;
cin >>k;
n = s.size();


memset(dp,-1,sizeof dp);
    for(int i=0; i<k; i++){
    	string t;
    	cin >>t;
st.insert(t);
    }

int ans = fun(s,0);
cout<<ans<<endl;









 
}