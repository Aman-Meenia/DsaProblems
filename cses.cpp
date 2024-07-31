#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;

// DECIMAL TO BINARY 
string decimaltobinary(long long  n){
string s;
    while(n>0){
        int k=n%2;
        s.push_back(k+'0');
        n=n/2;
        
    }
    while(s.size()<32){
        s.push_back('0');
    }
reverse(s.begin(),s.end());
    return s;
}
 
 
// BINARY TO DECIMAL 
 
ll binarytodecimal(string &s){
    int size=s.size();
    ll ans=0;
    int k=0;
    for(int i=size-1; i>=0; i--){
int t=s[i]-'0';
ans=ans+(pow(2,k)*t);
k++;
    }
    return ans;
}
 
 

 //  GCD AND LCM 
 
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a*b/gcd(a,b));}


//  POWER OF NUMBER


int mpow(int a, int b){
    ll ans  = 1;
while(b>0){
    if(b%2==1){
        ans = (ans%mod * a%mod) % mod;
    }
a=((ll)a%mod * a%mod) % mod;
  b >>= 1;

}
return ans%mod;
}

// prime number find 


vector<int> find_All_Prime(int n){
vector<int> ans;
vector<int> dp(n+1,true);
dp[0]=false;
dp[1]=false;


for(int i=2; i<=sqrt(n); i++){
if(dp[i]==true){
for(int k=i*i; k<=n; k=k+i){
    dp[k]=false;
}
}

}

for(int i=2; i<=n; i++){
if(dp[i]==true){
ans.push_back(i);
}
}


// for(auto it:ans)cout<<it<<" ";cout<<endl;

return ans;
}



// <------------------------------------------------------------------------------------->

// int dp[210][210][210][3];
// vector<int>  v;

// ll fun(int one , int zero , int k , int limit , int pre){

// if(k<0) return 0;

// if(one==0 && zero==0){
//     for(auto it:v)cout<<it<<" ";cout<<endl;
//     return 1;
// }


// if(dp[one][zero][limit][pre-1]!=-1) return dp[one][zero][limit][pre-1];
// ll ans = 0;
// ll ans1= 0;
// ll ans2= 0;

// if(pre==-1){
//     if(one>0){
//         v.push_back(1);
//    ans1= fun(one-1,zero,k-1,limit,1);
//    v.pop_back();
// }
// if(zero>0){
//     v.push_back(0);
//    ans2= fun(one,zero-1,k-1,limit,0);
//    v.pop_back();
// }
// }else{


// if(pre==1){
//     if(one>0){
//         v.push_back(1);
//    ans1= fun(one-1,zero,k-1,limit,1);
//    v.pop_back();
// }
// if(zero>0){
//     v.push_back(0);
//    ans2= fun(one,zero-1,limit-1,limit,0);
//    v.pop_back();
// }
// }else{

// if(zero>0){
//     v.push_back(0);
//    ans1= fun(one,zero-1,k-1,limit,0);
//    v.pop_back();
// }
// if(one>0){
//     v.push_back(1);
//    ans2= fun(one-1,zero,limit-1,limit,1);
// v.pop_back();
// }

// }


// }


// return dp[one][zero][limit][pre+1]=ans1+ans2;



// }


// int dp[210][210][210][3];


// ll fun(int one , int zero , int k , int limit , int pre){



// if(one==0 && zero==0){

//     return 1;
// }
// if(k<0) return 0;

// if(dp[one][zero][k][pre+1]!=-1) {
//     // cout<<" works "<<endl;
//     // return dp[one][zero][k][pre-1];
// }
// ll ans = 0;
// ll ans1= 0;
// ll ans2= 0;

// if(pre==-1){
//     if(one>0){

//    ans1= fun(one-1,zero,k-1,limit,1);

// }
// if(zero>0){

//    ans2= fun(one,zero-1,k-1,limit,0);

// }
// }else{


// if(pre==1){
//     if(one>0){

//    ans1= fun(one-1,zero,k-1,limit,1);

// }
// if(zero>0){

//    ans2= fun(one,zero-1,limit-1,limit,0);

// }
// }else{

// if(zero>0){

//    ans1= fun(one,zero-1,k-1,limit,0);

// }
// if(one>0){

//    ans2= fun(one-1,zero,limit-1,limit,1);

// }

// }

// }


// return dp[one][zero][k][pre+1]=(ans1%mod+ans2%mod)%mod;


// }



ll dp[210][210][3];

ll total_ways(int one , int zero , int limit , int k , int pre){



if(one==0 && zero==0){
// cout<<" works "<<endl;
//     for(auto it:v)cout<<it<<" ";cout<<endl;
 return 1;

}
if(dp[one][zero][pre+1]!=-1) return dp[one][zero][pre+1];

    // for(auto it:v)cout<<it<<" ";cout<<endl;
ll ans = 0 , ans1 =0, ans2 =0;


if(pre==-1){
 int n = min(one,limit);
    // cout<<" n "<<n<<endl;
    for(int i=0; i<n; i++){

// cout<<" works "<<endl;
// ans1+= total_ways((one-i)-1 , zero, limit, k , 1);
ans1=(ans1%mod+  total_ways((one-i)-1 , zero, limit, k , 1)%mod)%mod;


    }
    n =min(zero , limit);

for(int i=0; i<n; i++){

// ans2+= total_ways(one,(zero-i)-1,limit,k,0);
ans2=(ans2%mod+ total_ways(one,(zero-i)-1,limit,k,0)%mod)%mod;
}



}

if(pre==0){
    int n = min(one,limit);
    // cout<<" n "<<n<<endl;
    for(int i=0; i<n; i++){

ans1=(ans1%mod+  total_ways((one-i)-1 , zero, limit, k , 1)%mod)%mod;

    }
}else if(pre==1){
int n =min(zero , limit);

for(int i=0; i<n; i++){

ans2=(ans2%mod+ total_ways(one,(zero-i)-1,limit,k,0)%mod)%mod;

}


}


return  dp[one][zero][pre+1]=(ans1+ans2)%mod;


}


int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


//     int n ;
//     cin >>n;

// vector<int> v(n);
// for(int i=0; i<n; i++){
// cin>>v[i];
// }
// for(auto it:v)cout<<it<<" ";cout<<endl;


int zero, one , limit ;
cin >> zero >> one >>limit;

cout<<zero<<" onde "<<one<<" limit "<<limit<<endl;
memset(dp,-1,sizeof dp);

// int ans = fun(one,zero,limit,limit,-1);
// cout<<" ans1 "<<ans<<endl;
// int ans2 = fun(0,one,limit,limit,-1);
// cout<<ans1<<" ans2 "<<ans2<<endl;

int ans1 = total_ways(one, zero , limit,limit,-1);
// int ans2 = total_ways(one , zero-1,limit,limit,0);
// cout<<"ans1 "<<ans1<<" ans2 "<<ans2<<endl;
cout<<ans1<<endl;
// cout<<210*210*210*3<<endl;





}
