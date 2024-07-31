#define ll long long
#define mod 1000000007

class Solution {
public:
ll  dp[101][101];
ll fun(vector<int> &v , int index, int k ){


if(index>=v.size()){
    if(k==0) return 1;
    return 0;
}

if(dp[index][k]!=-1) return dp[index][k];
// choose in the subsequence 
ll ans=0;
if(v[index]<=k){
  ans= (ans%mod +fun(v,index+1,k-v[index])%mod)%mod;
}

// not choose int the subsequece
ans= (ans%mod+ fun(v,index+1,k)%mod)%mod;
// choose the subsequence but not in the sum
ans= (ans%mod+ fun(v,index+1,k)%mod)%mod;

return dp[index][k]=ans;
}




 int sumOfPower(vector<int>& v, int K) {
int dp[n+2][k+2];
        memset(dp,-1,sizeof dp);


        for(int i=n-1; i>=0; i--){

          for(int k=0; K<=K; k++){



          }


        }
        
        return fun(v,0,k);
    }
};
