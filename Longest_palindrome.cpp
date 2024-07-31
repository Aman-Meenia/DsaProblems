#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
 
 
 
string build_string(string & s){
string ans ;
int n = s.size();
for(int i=0; i<n; i++){
    ans.push_back('#');
    ans.push_back(s[i]);
}
ans.push_back('#');
return ans;
}
 
vector<int> dp;
 
void manacher_algorithm(string & s){
 
int n = s.size();
 
dp.assign(n+1,1);
 
int l = 0;
int r = 0;
 
for(int i=1; i<n; i++){
dp[i]=max(0,min(r-i,dp[l+r-i]));
while(i+dp[i]<n && i-dp[i]>=0 && s[i+dp[i]]==s[i-dp[i]]){
    dp[i]++;
}
if(i+dp[i]>r){
    r=i+dp[i];
    l=i-dp[i];
}
}

for(auto it:dp)cout<<it<<" ";cout<<endl;
 
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
string t= s;
s = build_string(s);
 
 manacher_algorithm(s);
// cout<<s<<endl;
// for(auto it:ans)cout<<it<<" ";cout<<endl;
 
    // For getting the maximum length palindrome
int n = s.size();
int ans= 1;
    for(int i=0; i<n; i++){
ans= max(ans,dp[i]-1);
    }
    // cout<<ans<<endl;
 
 
    for(int i=0; i<n; i++){
 
        if(dp[i]-1==ans){
 
            if(ans%2==0){
int index1 = i/2-1;
// int index2 = i/2;
 
int start = index1-(ans/2-1);
// int end = index2+(ans/2-1);
 
cout<<t.substr(start,ans)<<endl;
break;
 
            }else{
                int index = i/2;
 
              int start = index-(ans/2);
              // int end = index+(ans/2);
              // cout<<" start "<<start<<" end "<<end<<endl;
 
cout<<t.substr(start,ans)<<endl;
break;
 
            }
 
 
        }
    }
 
 
 
 
 
 
 
 
}