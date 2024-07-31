#include<bits/stdc++.h>
#define ll long long
using namespace std;


set<string> st;
int n;
int dp[5010];
int diff_ways(string & s , int index ){

if(index>=n){
    return 1;
}
int ans = 0;
if(dp[index]!=-1) return dp[index];
string t;
for(int i=index; i<n; i++){
t.push_back(s[i]);

if(st.find(t)!=st.end()){
    int temp_ans= diff_ways(s,i+1);
    ans+=temp_ans;
}
}
return dp[index]=ans;
}




void fun(){


    string s;
    cin>> s;
     n = s.size();
    int k ;
    cin >> k;
    vector<string> t;
    while(k--){
string temp;
cin >> temp;
t.push_back(temp);
    }


    for(auto it:t){
        st.insert(it);
    }
    memset(dp,-1,sizeof dp);
    int ans = diff_ways(s,0);
    cout<<ans<<endl;

}



int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

int t=1;
// cin >>t;

while(t--){
    fun();
}



}