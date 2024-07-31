#include<bits/stdc++.h>
#define ll long long
using namespace std;




struct node{

int cnt;

node(){
	cnt= 0;
}

};


node t[4*100100];

// merge

node merge(node a , node b){
	node ans;

ans.cnt = a.cnt+b.cnt;
	return ans;
}


// build

#define mid  (l+(r-l)/2)

void build(int index , int l , int r){

if(l==r){
	t[index].cnt= 1;
	return;
}

build(2*index, l , mid );
build(2*index+1,mid+1,r);
t[index]=merge(t[2*index],t[2*index+1]);

}

// update 

void update(int index , int l , int r , int lq , int rq){


if(lq>r || rq<l){
	return ;
}

if(lq<=l && rq>=r){
t[index].cnt = 0;
	return ;
}


update(2*index , l , mid , lq , rq);
update(2*index+1, mid+1 , r, lq , rq);
t[index]= merge(t[2*index],t[2*index+1]);

}


// get_ans


int get_query(int index , int l  , int r , int target){


if(l==r){
	return l;
}

if(t[2*index].cnt>=target) return get_query(2*index , l , mid , target);
return get_query(2*index+1, mid+1 , r , target-t[2*index].cnt);


}


#undef mid


int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


    int n ;
cin >> n;
vector<int> height(n);
vector<int> infront(n);

for(int i=0; i<n; i++){
cin >> height[i];
}

for(int i=0; i<n; i++){
    cin >> infront[i];
}


vector<vector<int>> v;

for(int i=0; i<n; i++){
    v.push_back({height[i],infront[i]});
}


sort(v.begin(),v.end());
build(1,0,n-1);

// for(auto it:v){
// 	cout<<it[0]<<" # "<<it[1]<<endl;
// }cout<<endl;


vector<int> ans(n,0);

for(int i=0; i<n; i++){

int front = v[i][1];

int index = get_query(1,0,n-1,front+1);
update(1,0,n-1,index,index); 
ans[index]=v[i][0];



}


for(auto it:ans)cout<<it<<" ";cout<<endl;












}