#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;


// NODE STRUCTURE 
struct  node{

ll min_val;

node(){
	min_val=LLONG_MAX;

}
};

// ARRAY DECLERATION FOR STORING SEGMENT TREE
node t[4*200010];


// TO MERGE TWO NODE (BASED ON THE TYPE OF PROBLEM)

node merge_node(node a, node b){
	node ans;
	ans.min_val=min(a.min_val,b.min_val);
	return ans;
}

// BUILD FUNCITON TO BUILD SEGMENT TREE

void build(int id , int l , int r , vector<int> &v ){

if(l==r){
	t[id].min_val=v[l];
	return ;
}

int mid = l + (r-l)/2;

build(2*id,l,mid,v);
build(2*id+1,mid+1,r,v);
t[id]=merge_node(t[2*id],t[2*id+1]);



}


//  TO UPDATE RANGE QUERIES (Single / Point query)

void update_query(int id ,int l , int r ,int pos , int val ){


if(pos<l||pos>r) return ;

if(l==r){
t[id].min_val=val;
return ;
}

int mid = l + (r-l)/2;
update_query(2*id,l,mid,pos,val);
update_query(2*id+1,mid+1,r,pos,val);
t[id]=merge_node(t[2*id],t[2*id+1]);

}


//  GET QUERY 

node get_query(int id , int l , int r, int lq , int rq){

if(l>rq || lq>r) return node();

if(l>=lq && r<=rq){
return t[id];
}

int mid = l + (r-l)/2;

node a = get_query(2*id,l,mid,lq,rq);
node b = get_query(2*id+1,mid+1,r,lq,rq);

return merge_node(a,b);


}




int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


int n , q ;
cin >> n >> q;

vector<int> v(n);
for(int i=0; i<n; i++){
	cin >>v[i];
}

build(1,0,n-1,v);

while(q--){

int query_type;
cin >> query_type;

if(query_type==1){
int pos , val;
cin >> pos >> val;
pos--;
update_query(1,0,n-1,pos,val);
}else{
int l , r;
cin >> l >>r;
l-- , r--;
cout<<get_query(1,0,n-1,l,r).min_val<<endl;

}

}







}
