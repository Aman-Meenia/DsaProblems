#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;



struct node{

int val;

node(){
val=0;
}

};

node t[4*200100];

// merge

node merge(node a , node b){
    node ans;
    ans.val=max(a.val,b.val);

    return ans;
}

// build

void build(int id , int l , int r , vector<int> &v){

if(l==r){
t[id].val=v[l];
    return ;
}

int mid = l +(r-l)/2;

build(2*id,l,mid,v);
build(2*id+1,mid+1,r,v);
t[id]=merge(t[2*id],t[2*id+1]);

}

// updat query

void update(int id , int l , int r , int lq , int rq , int val){

if(lq>r||rq<l){
    return ;
}
if(l>=lq && r<=rq){
    t[id].val-=val;
    return ;
}
int mid = l +(r-l)/2;
update(2*id,l,mid,lq,rq,val);
update(2*id+1,mid+1,r,lq,rq,val);
t[id]=merge(t[2*id],t[2*id+1]);

}



// get_query

int get_query(int id ,int l , int r , int k){


if(t[id].val>=k){

if(l==r){

    return l;
}

int mid = l+(r-l)/2;
if(t[2*id].val>=k){
return get_query(2*id,l,mid,k);
}
if(t[2*id+1].val>=k){
return get_query(2*id+1,mid+1,r,k);
}


}

return -1;

}





int main(){
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif




int n , k;
cin >>n >>k;
vector<int> v(n);
for(int i=0; i<n; i++){
    cin >>v[i];
}

build(1,0,n-1,v);


while(k--){
int val;
cin >>val;
int ans = get_query(1,0,n-1,val);
cout<<ans+1<<" ";
if(ans!=-1){
    update(1,0,n-1,ans,ans,val);
}


}







}