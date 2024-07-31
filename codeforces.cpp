#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<unordered_set> 
#include<math.h>
#include<algorithm>
#define py cout<<"Yes\n";
#define pn cout<<"No\n";

#define google(i) cout<<"Case #"<<i<<": ";
 
#define mod 1000000007
#define pi 3.141592653589793238
  
#define ll long long
#define ull unsigned long long  
#define pb push_back
#define fi first
#define bg begin();
#define en end();
#define se second 
#define mpp make_pair
#define F first
#define S second
 
#define fl(i,n) for(ll i=0;i<n;i++)
#define fll(i,start,end) for(ll i=start;i<end;i++)
#define rl(i,m,n) for(ll i=n;i>=m;i--)
#define all(v) v.begin(),v.end()
 
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define AmanMeenia cout.tie(NULL);

using namespace std;
 



 /************************ ------------------------------------------------------ ************************/

// DECIMAL TO BINARY 
string decimaltobinary(long long  n){
string s;
    while(n>0){
        int k=n%2;
        s.push_back(k+'0');
        n=n/2;
        
    }
    // while(s.size()<32){
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




 /************************ ------------------------------------------------------ ************************/
 
//  WRITE CODE HERE 


 /************************ ------------------------------------------------------ ************************/
int  main( ){
    #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
int n ;
cin >>n;


    vector<int> v(n);

for(int i=0; i<n; i++){
    cin >>v[i];
}






}


 /************************ ------------------------------------------------------ ************************/

// priority_queue<pair<int,pair<int,int> > , vector<pair<int,pair<int,int> >>,greater<pair<int,pair<int,int> >> >pq;
 
// priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> >> >pq;

// priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> >,greater< pair<int,pair<int,int> >> pq;
