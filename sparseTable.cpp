#include<bits/stdc++.h>
#define ll long long 
using namespace std;

// Build sparse table

int dp[200100][25];



void build_sparse_table(vector<int> & v){
int n = v.size();

for(int i=n-1; i>=0; i--){

  for(int k=0; k<=25; k++){

    ll index = i+pow(2,k)-1;
    if(index>=n) break;

    if(k==0){
      dp[i][k]=v[i];
    }else{
      int temp = pow(2,k-1)+i;
      // change according to question 
      dp[i][k]=max(dp[i][k-1],dp[temp][k-1]);
    }


  }




}

}

string decimal_to_binary(int n){
string s;
while(n>1){
  if(n%2==0){
    s.push_back('0');
  }else{
    s.push_back('1');
  }
  n=n/2;
}
s.push_back('1');
reverse(s.begin(),s.end());

return s;

}

int ans_query(int l , int r){

int total = r-l+1;

string s = decimal_to_binary(total);

// change according to question 
int ans = INT_MIN;

int index = s.size()-1;
for(int i=0; i<s.size(); i++){
  if(s[i]=='1'){
// change according to question
ans = max(ans,dp[l][index]);
l+=pow(2,index);

  }


index--;
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
int n , k;
cin >>n >> k;


vector<int> v(n);
for(int i=0; i<n; i++){
  cin>>v[i];
}
memset(dp,-1,sizeof dp);
// for(auto it:v){
//   cout<<it<<" ";
// }cout<<endl;


build_sparse_table(v);


// for(int i=0; i<n; i++){
//   for(int k=0; k<25; k++){
// cout<<dp[i][k]<<" ";
//   }cout<<endl;
// }cout<<endl;



int cnt = 0;
while(k--){
  int l , r ;
cin >> l >> r;
l-- ,r--;
// cout<<" l "<<l<<" r "<<r<<endl;
int ans = ans_query(l,r);
// cout<<" ans "<<ans<<endl;

if(ans<=v[l]){
cnt++;
}


}

cout<<cnt<<endl;


  return 0;
}
