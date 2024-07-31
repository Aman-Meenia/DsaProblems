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
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
#define fl(i,n) for(int i=0;i<n;i++)
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fll(i,start,end) for(ll i=start;i<end;i++)
#define rl(i,m,n) for(ll i=n;i>=m;i--)
#define all(v) v.begin(),v.end()
 
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define AmanMeenia cout.tie(NULL);
using namespace std;
 // __builtin_popcount(100)

 /************************ ------------------------------------------------------ ************************/

struct node{

ll cnt;

node(){
    cnt = 0;
}

};

node t1[int(4*1e6+10)];
node t2[int(4*1e6+10)];


// merge 


node merge(node &a , node & b){
    node ans;
    ans.cnt = a.cnt+b.cnt;
    return ans;
}

// build

void build(int id , int l ,  int r  , vector<int>& v){

if(l==r){
t2[id].cnt=1;
return ;
}

int mid =  l+(r-l)/2;

build(2*id , l , mid , v);
build(2*id+1 , mid+1, r , v);
t2[id]=merge(t2[2*id],t2[2*id+1]);


}


// Update 

void updatet1(int id , int l , int r , int lq , int rq , int val){

if(lq>r||rq<l){
    return ;
}

if(l>=lq&&r<=rq){
t1[id].cnt = val;
    return ;
}

int mid = l +(r-l)/2;

updatet1(2*id, l , mid , lq , rq , val);
updatet1(2*id+1 , mid+1, r , lq , rq , val);
t1[id]=merge(t1[2*id],t1[2*id+1]);

}

//Update

void updatet2(int id , int l , int r , int lq , int rq , int val){

if(lq>r||rq<l){
    return ;
}

if(l>=lq&&r<=rq){
t2[id].cnt = val;
    return ;
}

int mid = l +(r-l)/2;

updatet2(2*id, l , mid , lq , rq , val);
updatet2(2*id+1 , mid+1, r , lq , rq , val);
t2[id]=merge(t2[2*id],t2[2*id+1]);

}


// getAnswer

node getAnswert1(int id , int l , int r , int lq , int rq ){

if(lq>r || rq<l){
    return node();
}

if(l>=lq && r<=rq){
    return t1[id];
}


int mid = l +(r-l)/2;
node ans1 = getAnswert1(2*id,l,mid,lq,rq);
node ans2 = getAnswert1(2*id+1,mid+1,r,lq,rq);

return merge(ans1,ans2);


}

// get answer
node getAnswert2(int id , int l , int r , int lq , int rq ){

if(lq>r || rq<l){
    return node();
}

if(l>=lq && r<=rq){
    return t2[id];
}


int mid = l +(r-l)/2;
node ans1 = getAnswert2(2*id,l,mid,lq,rq);
node ans2 = getAnswert2(2*id+1,mid+1,r,lq,rq);
// cout<<ans1.cnt<<" ans2 "<<ans2.cnt<<endl;
return merge(ans1,ans2);


}







 /************************ ------------------------------------------------------ ************************/
int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

    int n ;
    cin >> n ;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >>v[i];
    }

// coordinate compression
unordered_map<ll,ll> mp;

set<ll> st;

for(auto it:v){
    st.insert(it);
}

int val = 0;
for(auto it:st){
mp[it]=val;
val++;
}


// for right side build tree
// vector<int>tt(1000000);
    build(1,0,n-1,v);

ll ans = 0;
int firstval = mp[v[0]];


updatet1(1,0,n-1,firstval,firstval,1);
updatet2(1,0,n-1,firstval,firstval,0);

for(int i=1; i<n-1; i++){

//  get maximum value t1
int val = mp[v[i]];
node left = getAnswert1(1,0,n-1,val+1,n-1);


// get minimum value for t2
node right = getAnswert2(1,0,n-1,0,val-1);
// ll temp =0;
ll temp = left.cnt * right.cnt;
ans+=temp;

updatet1(1,0,n-1,val,val,1);
updatet2(1,0,n-1,val,val,0);
}

cout<<ans<<endl;

   

}