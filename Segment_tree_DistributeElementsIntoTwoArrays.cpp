#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;



struct node{

int cnt ;

node(){
    cnt =0;
}

};

node t1[4*100010];
node t2[4*100010];

// merge 

node merge(node & a , node & b){

node ans;
ans.cnt = a.cnt +b.cnt;
    return ans;

}

// build

void build(int id , int l , int r , vector<int> & v , node t[]){

if(l==r){
    t[id].cnt=1;
    return ;
}
int  mid = l +(r-l)/2;
build(2*id,l,mid,v,t);
build(2*id+1,mid+1,r,v,t);
t[id]=merge(t[2*id],t[2*id+1]);
}


// update 

void update(int id , int l , int r , int lq , int rq , int val , node t[]){

if(lq>r || rq<l){
    return;
}
if(l>=lq && r<=rq){

t[id].cnt=t[id].cnt+1;
    return ;
}

int mid =  l +(r-l)/2;

update(2*id,l,mid, lq,rq,val,t);
update(2*id+1, mid+1 , r , lq , rq ,val, t);
t[id]=merge(t[2*id],t[2*id+1]);


}


// get answer

node get_query(int id , int l  , int r , int lq , int rq , node t[]){


if(lq>r||rq<l){
    return node();
}

if(l>=lq && r<=rq){
    return t[id];
}

int mid = l +(r-l)/2;

node ans1 = get_query(2*id,l,mid,lq,rq,t);
node ans2 = get_query(2*id+1,mid+1,r,lq,rq,t);

return merge(ans1,ans2);

}


int main(){
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


int n ;
cin >> n;


vector<int> v(n);


for(int i=0; i<n; i++){
    cin >>v[i];
}


// coordinate compression
unordered_map<int,int> mp;
set<int> st;
for(auto it:v){
    st.insert(it);
}

int cnt = 0;
for(auto it:st){
    mp[it]=cnt;
    cnt++;
}




// segment tree call 

// build(1,0,n-1,v,t1);


// cout<<get_query(1,0,n-1,2,3,t2).cnt<<endl;



vector<int> ans1;
vector<int> ans2;
for(int i=0; i<n; i++){

int val = mp[v[i]];

if(i==0){


    update(1,0,n-1,val,val,1,t1);
    ans1.push_back(v[i]);
cout<<val<<endl;
}else if(i==1){
    cout<<val<<endl;
  update(1,0,n-1,val,val,1,t2);
    ans2.push_back(v[i]);

}else{

   int first = get_query(1,0,n-1,val+1,n-1,t1).cnt;
   int second = get_query(1,0,n-1,val+1,n-1,t2).cnt; 

if(second>first||first==second && ans2.size()<ans1.size()){
    // cout<<" val "<<val<<endl;
 update(1,0,n-1,val,val,1,t2);
     ans2.push_back(v[i]);
}else{
    update(1,0,n-1,val,val,1,t1);  
        ans1.push_back(v[i]);
}


}


}
// cout<<get_query(1,0,n-1,1,1,t1).cnt<<endl;
   // int second = get_query(1,0,n-1,0,n-1,t2).cnt;
   // cout<<" Second "<<second<<endl; 
// for(auto it:ans1)cout<<it<<" ";cout<<endl;
//     for(auto it:ans2) cout<<it<<" ";cout<<endl;
for(auto it:ans2){
ans1.push_back(it);
}


for(auto it:ans1){
    cout<<it<<" ";
}cout<<endl;










}
