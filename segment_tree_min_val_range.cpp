#include<bits/stdc++.h>
using namespace std;


struct node{
	int min_val;

	node(){
min_val=INT_MAX;
	}
};

// array decleration
node t[4*200100];

// merge tree

node merge(node a , node b){
node ans ;
ans.min_val=min(a.min_val,b.min_val);
return ans;
}


// build tree 

void build(int id , int l , int r , vector<int>&v){

if(l==r){
t[id].min_val=v[l];
	return;
}

int mid = l+(r-l)/2;

build(2*id,l,mid,v);
build(2*id+1,mid+1,r,v);
t[id]=merge(t[2*id],t[2*id+1]);

}


// get ans

node get_query(int id ,int l , int r , int lq ,int rq){



if(lq>r||rq<l){
	return node();
}


if(l>=lq && r<=rq){
	return t[id];
}

int mid = l+(r-l)/2;

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


int n , k ;
cin >> n >> k;

vector<int> v(n);
for(int i=0; i<n; i++){
	cin >>v[i];
}

build(1,0,n-1,v);

while(k--){

int lq , rq;
cin >> lq  >> rq;
lq--;
rq--;


node ans = get_query(1,0,n-1,lq,rq);

cout<<ans.min_val<<endl;




}




	return 0;
}