#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
#define N 200010


int dp[N][25];
//  SPARSE TABLE TO FIND MINIMUM NUMBER 
void build_sparse_table(vector<int> & v){
int n = v.size();
for(int i=n-1; i>=0; i--){
for(int k=0; k<25; k++){
int t = pow(2,k-1);
int R = i+pow(2,k)-1;
if(R>=n) break;
    if(k==0) dp[i][k]=v[i];
    else dp[i][k]=min(dp[i][k-1],dp[i+t][k-1]);
}

}


}



string  decimal_to_binary(int n){
string s;
while(n>0){
    s.push_back(n%2+'0');
    n=n/2;
}
reverse(s.begin(),s.end());
return s;

}




int ans_queries(int left , int right){
int total = right-left+1;
string s = decimal_to_binary(total);
int size = s.size()-1;
int  ans = INT_MAX;
for(int i=0; i<s.size(); i++){
    if(s[i]=='0'){
        size--;
        continue;
    }
ans = min(ans,dp[left][size]);
left=left+pow(2,size);
size--;


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

int n, q;
cin >>n >> q;
vector<int> v(n);
for(int i=0; i<n; i++){
    cin >>v[i];
}

// for(auto it:v){
//     cout<<it<<" ";
// }cout<<endl;

// for(int i=0; i<8; i++){
//     for(int j=0; j<4; j++){
//         cout<<dp[i][j]<<" ";
//     }cout<<endl;
// }

memset(dp,0,sizeof dp);
build_sparse_table(v);
while(q--){
    int left , right;
    cin >> left >> right;
    left-- , right--;
    cout<<ans_queries(left,right)<<endl;
}






}
