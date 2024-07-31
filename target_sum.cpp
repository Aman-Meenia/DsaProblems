#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
int dp[1000][10000];

int target_sum(vector<int> &v , int id , int target){

  if(target==0) return 1;
  if(id>=v.size()) return 0;
  if(dp[id][target]!=-1) return dp[id][target];
  int ans = 0; 
  if(v[id]<=target){
    ans+=target_sum(v,id+1,target-v[id]);
  }
   ans+=target_sum(v,id+1,target);
cout<<" ans "<<ans<<endl;
   return dp[id][target]=ans;
}


//  FOR -VE TARGET ALSO 
int target_sum2(vector<int> & v ,int id ,  int target , int val){

if(val==target && id==v.size()){
  return 1;
}
if(val<0){
if(dp[id][(-val)+1001]!=-1) return dp[id][(-val)+1001];
}else{
    if(dp[id][val]!=-1) return dp[id][val];
}

if(id>=v.size()) return 0;


int ans =0;
ans+=target_sum2(v,id+1,target,val+v[id]);
ans+=target_sum2(v,id+1,target,val-v[id]);
if(val<0){
dp[id][(-val)+1001]=ans;
}else{
dp[id][val]=ans;
}
return ans;
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
  vector<int> v(n);
  for(int i=0;i<n; i++){
    cin >>v[i];
  }
  memset(dp,-1,sizeof dp);
for(auto it:v)cout<<it<<" ";cout<<endl;

 cout<<target_sum(v,0,28)<<endl;

}
