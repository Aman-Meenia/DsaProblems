#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;



struct node{

int val;
int cnt;
node(){
    val=0;
    cnt = 0;
}

};

node t[4*200100];

// merge 

node merge(node a , node b){

node ans ;
ans.cnt = a.cnt+b.cnt;
return ans;

}

// build

void build(int id , int l , int r , vector<int>&v){


if(l==r){
    t[id].val=v[l];
    t[id].cnt=1;
    return ;
}

int mid = l + (r-l)/2;
build(2*id,l,mid,v);
build(2*id+1,mid+1,r,v);

t[id]=merge(t[2*id],t[2*id+1]);

}

// update query

void update(int id , int l , int r  , int lq , int rq){

if(lq>r ||rq<l){
    return ;
}

if(l>=lq && r<=rq){
    t[id].val=0;
    t[id].cnt=0;

return ;
}

int mid = l +(r-l)/2;

update(2*id,l,mid,lq,rq);
update(2*id+1,mid+1,r,lq,rq);
t[id]=merge(t[2*id],t[2*id+1]);

}

// get query

void get_query(int id , int l , int r , int index , int val){



}


int main(){
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif









}