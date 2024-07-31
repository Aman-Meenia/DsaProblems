#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;

int total ;
int dp[20][2][20 * 9 + 1]; 
ll digit_dp(string &s ,int target, int index , bool cnd){
if(target>total) return 0;
if(index==s.size() && target==total) return 1;
if(index>s.size()) return 0;

if(dp[index][cnd][target]!=-1) return dp[index][cnd][target];
ll ans = 0;
for(int digit=0; digit<=9; digit++){

  if(cnd==true){
    if(digit>s[index]-'0') continue;

      if(digit==s[index]-'0'){
    ans+= digit_dp(s,target+digit,index+1,true);
      }else 
    ans+=digit_dp(s,target+digit,index+1,false);
    
  }else{
   ans+= digit_dp(s,target+digit,index+1,false);


  }


}

return dp[index][cnd][target]=ans;


}


int fun(int i){
  string s= to_string(i);
  int sum =0;
  for(auto it:s){
    sum+=it-'0';
  }
  return sum;
}


int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

string s;
cin >>s;

total = 28;

// int cnt =0;
// for(int i=48955; i<10000000; i++){

// if(fun(i)==28){
// cnt++;
// }


// }
// cout<<cnt<<endl;

memset(dp,-1,sizeof dp);
int ans = digit_dp(s,0,0,true);
cout<<ans<<endl;


}
