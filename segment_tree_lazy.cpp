#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;



struct node{

int lazy;
int  val;
int power; 

node(){
    lazy=0;
    val=0;
    power=0;
}



};

node t[4*100000];

node merge(node &a , node & b){
node ans;

ans.val=(a.val%mod+b.val%mod)%mod;
ans.power = (a.power%mod+b.power%mod)%mod;
ans.lazy =0;

return ans;

}

void lazyPush(int id , int l , int r){

if(t[id].lazy){

    t[id].power += (2*t[id].lazy*t[id].val)%mod+(t[id].lazy*t[id].lazy%mod)*(r-l+1);
    t[id].val+=t[id].lazy*(r-l+1);
    t[id].power%=mod;
    t[id].val%=mod;
    if(l!=r){
        t[2*id].lazy=t[id].lazy;
        t[2*id+1].lazy=t[id].lazy;
    }
    t[id].lazy=0;
}


}


void update(int id , int l  , int r , int lq , int rq , int val){
lazyPush(id,l,r);
if(lq>r || l>rq){
return ;
}

if(l>=lq && r<=rq){
t[id].lazy+=1;
lazyPush(id,l,r);
    return ;
}
int mid = l + (r-l)/2;

update(2*id , l , mid,lq,rq,val);
update(2*id+1,mid+1,r,lq,rq,val);
merge(t[2*id],t[2*id+1]);


}


node get_query(int id , int l , int r , int lq , int rq ){
lazyPush(id,l,r);
if(lq>r || rq<l){
    return node();
}
if(l>=lq && r<=rq){
return t[id];
}
int mid = l + (r-l)/2;
node ans1 =  get_query(2*id,l,mid,lq,rq);
node ans2 = get_query(2*id+1,mid+1,r,lq,rq);

return merge(ans1,ans2);

}







int main(){
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

int n;
cin >>n;
vector<int> v(n);
for(int i=0; i<n; i++){
    cin >>v[i];
}

unordered_map<int,int> mp;
for(int i=0; i<n; i++){
int preIndex = -1;
if(mp.find(v[i])!=mp.end()){
    preIndex=mp[v[i]];
}

update(1,0,n-1,preIndex+1,i,1);

node temp_ans = get_query(1,0,n-1,0,i);
cout<<temp_ans.power<<endl;


mp[v[i]]=i;

}




}
