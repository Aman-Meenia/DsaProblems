#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;

ll mpow(ll a , ll b){

ll ans =1;
while(b>0){

  if(b%2==1){
ans = (ans*a)%mod;
  }
  a=(a%mod*a%mod)%mod;

  b=b/2;

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


 
 //To calculate (a/b)%mod -> (a * mpow(b))%mod
int a = 10;
int b = 232384;
cout<<mpow(b,mod-2)<<endl;


}

