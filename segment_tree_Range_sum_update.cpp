#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;





struct node{

ll sum;

node(){
    sum = 0;
}


};

node t[4*200100];

// merge 

node merge(node a , node b){
    node ans;

    ans.sum = a.sum+b.sum;
    return ans;
}

// build 

void build(int id , int l , int r , vector<int>&v){

if(l==r){

    t[id].sum=v[l];
    return ;
}

int mid = l +(r-l)/2;

build(2*id,l,mid,v);
build(2*id+1,mid+1,r,v);
t[id]=merge(t[2*id],t[2*id+1]);

}



// update

void update(int id , int l , int r , int lq, int rq  , int val){

if(lq>r||rq<l){
    return ;
}
if(l>=lq && r<=rq){
t[id].sum=val;
return ;

}

int mid = l + (r-l)/2;
update(2*id,l,mid,lq,rq,val);
update(2*id+1,mid+1,r,lq,rq,val);
t[id]=merge(t[2*id],t[2*id+1]);


}


// get ans
node get_query(int id , int l , int r , int lq, int rq ){

if(lq>r||rq<l){
    return node();
}
if(l>=lq && r<=rq){
    return t[id];
}
int mid = l + (r-l)/2;

node ans1 = get_query(2*id,l,mid,lq,rq);
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



int n , k;
cin >>n >>k;

vector<int> v(n);
for(int i=0; i<n; i++){
    cin >>v[i];
}

build(1,0,n-1,v);
while(k--){

int a , b , c;
cin >> a >> b >> c;
if(a==1){
    b--;
    // update 
update(1,0,n-1,b,b,c);

}else{

    b--, c--;
    // get_query
    node ans = get_query(1,0,n-1,b,c);
cout<<ans.sum<<endl;

}



}






}