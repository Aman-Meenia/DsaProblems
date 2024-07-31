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
    // while(s.size()<64){
    //     s.push_back('0');
    // }
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

unordered_set<int> st;
string t;
ll dp[101][3][3];
ll fun(string & s , int index, int val , int cnd){
// cout<<" works "<<endl;
if(index>=s.size()){
    // cout<<t<<endl;
    return 1;
}

if(dp[index][val+1][cnd]!=-1) return dp[index][val+1][cnd];
ll ans1=0,ans2=0;

if(s[index]=='0'){
    t.push_back('0');
ans1=fun(s,index+1,0,false);
t.pop_back();

if(cnd==true){
    ans2=fun(s,index+1,1,true);
}
}else{
    t.push_back('1');
ans1=fun(s,index+1,1,false);
t.pop_back();
t.push_back('0');
ans2=fun(s,index+1,0,true);
t.pop_back();

}

return dp[index][val+1][cnd]=ans1+ans2;
}

  

int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif




// for(ll i=8234780928340; i<=10; i++){
    cout<<decimaltobinary(8234780928340)<<endl;
// }
    st.insert(4);

        st.insert(5);

    st.insert(6);

    st.insert(7);

//     st.insert(8);

// // string s = "10000001010101";
//     memset(dp,-1,sizeof dp);
// ll ans = fun(s,0,-1,false);
//     memset(dp,-1,sizeof dp);
// cout<<ans<<endl;



// ll low = 0;

// ll high = LLONG_MAX;

int x = 7;
int n = 2;
string a = decimaltobinary(x);
cout<<a<<endl;
// strimemset(dp,-1,sizeof dp);(s,0,-1,false);
ll low = 1;
ll high = LLONG_MAX;


while(low<=high){
ll mid = low + (high/low)/2;
memset(dp,-1,sizeof dp);
string s = decimaltobinary(mid);
cout<<mid<<endl;

ll ans = fun(s,0,-1,false);
if(ans>=n){
high = mid-1;
}else{
    low=mid+1;
}



}
cout<<low<<endl;
string ans ;
string s = decimaltobinary(low);
// for(int ifun(s,0,-1,false)
cout<<" A "<<a<<endl;
int index = a.size()-1;
cout<<" index "<<index<<endl;
reverse(a.begin(),a.end());
for(int i=s.size()-1; i>=0; i--){
if(index>=0 && a[index]=='1'){
    ans.push_back('1');
    cout<<" ehllo "<<endl;
    index--;
}
ans.push_back(s[i]);
}
cout<<ans<<endl;
// while(low<=high){


// ll mid = low +(high-low)/2;

// if(mid<x){
//     low=mid+1;
//     cout<<" adf "<<endl;
// }else{

// string s = decimaltobinary(mid);
// int index = a.size()-1;
// string newS;
// // cout<<"a "<<a<<endl;
// for(int i=s.size()-1; i>=0; i--){

// if(a[index]=='1' && index>=0){
//     s[i]='1';
// }else{
//     newS.push_back(s[i]);
// }
// index--;
// if(index<0){
//     break;
// }
// }
// reverse(newS.begin(),newS.end());
//  memset(dp,-1,sizeof dp);
// ll ans = fun(newS,0,-1,false);
// cout<<ans<<" mid "<<mid<<endl;
// if(ans>n){
// high = mid-1;
// }else{
//     low = mid+1;
// }




// }



// }

// cout<<" low "<<low<<endl;







}
