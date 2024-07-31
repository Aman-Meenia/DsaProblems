#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct node{
	int maxi;

	node(){
		maxi = 0;
	}
};


node t[5*40000];
#define mid (l+(r-l)/2)
// merge 

node merge(node a , node b){
	node ans ;
	ans.maxi =  max(a.maxi,b.maxi);
	return ans;
}

// no need of build

// update

void update(int index , int l , int r , int pos , int val){
if(pos<l || pos>r){
	return ;
}
cout<<" index "<<index<<" l "<<l<<" r "<<r<<" mid "<<mid<<endl;

if(l==r){
	t[index].maxi=val;
	// cout<<" index "<<index<<" l " <<l<<" val "<<val<<endl;
	return ;
}
// int mid= l +(r-l)/2;

update(2*index,l,mid,pos,val);
update(2*index+1,mid+1,r,pos,val);
t[index]= merge(t[2*index],t[2*index+1]);
// cout<<" index "<<index<<" val "<<t[index].maxi<<" l "<< l<<" r "<<r<<endl;
}

// get answer 

int get_query(int index , int l  , int r , int lq , int rq ){

if(lq>r || rq<l) return 0;

if(lq<=l && rq>=r){
	// cout<<"works "<<endl;
	// cout<<"l "<<l<<" r "<<r<<" lq "<<lq<<" rq "<<rq<<endl;
	cout<<index<<" l "<<l<<" t[index] "<<t[index].maxi<<endl;
	if(t[index].maxi+l>rq){
		return rq-l;
	}
	return t[index].maxi;
}
// int mid= l +(r-l)/2;
int ans1 = get_query(2*index,l,mid,lq,rq);
int ans2 = get_query(2*index+1,mid+1,r,lq,rq);

return max(ans1,ans2);
}





int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


int n = 20;
// update(1,0,n,0,20); 

// cout<<get_query(1,0,n,0,20)<<endl;

update(1,0,n,0,4);
for(int i=0; i<35; i++){
	cout<<t[i].maxi<<"  ";
}cout<<endl;
update(1,0,n,4,16);

// update(1,0,n,0,4);

for(int i=0; i<35; i++){
	cout<<t[i].maxi<<"  ";
}cout<<endl;

cout<<get_query(1,0,n,0,10)<<endl;





}