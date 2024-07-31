#include <bits/stdc++.h>
#define ll long long 
using namespace std;
 
 
 
 
struct  node
{
	ll val ;
	ll lazy ;
	node(){
		val =0;
		lazy = 0;
	}
	
};
 
 
//  MERGE 
 
// node merge(node& a, node &b){
// 	node ans;
// 	ans.sum = a.sum + b.sum;
 
// 	return ans;
// }
 
node t[4*200010];
//  build
void build(ll index , ll left , ll right ,vector<ll> &v){
	if(left==right){
		t[index].val=v[left];
		t[index].lazy=0;
		return ;
	}
 
	ll mid = left + (right-left)/2;
 
	build(index*2,left,mid,v);
	build(index*2+1,mid+1,right,v);
	// t[index].lazy=0;
	// t[index].val=0;
}
 
 
//  lazy
 
void push_lazy(ll index , ll left , ll right){
// propogate the lazy to the children  
if(left!=right){
	t[index*2].lazy+=t[index].lazy;
	t[index*2+1].lazy+=t[index].lazy;
}
t[index].val=t[index].val+t[index].lazy;
t[index].lazy=0;
}
 
 
//  Update
void update(ll index  , ll left , ll right ,  ll lq , ll rq, ll val ){
push_lazy(index , left , right);
if(lq>right || rq<left) return;
 
if(left>=lq && right<=rq){
	t[index].lazy+=val;
	push_lazy(index,left,right);
	return ;
}
	ll mid = left + (right-left)/2;
 
	update(index*2,left,mid,lq,rq,val);
	update(index*2+1,mid+1,right,lq,rq,val);
 
}
 
 
// query 
 
ll query( ll index , ll left , ll right , ll pos){
 
push_lazy(index,left,right);
if(pos<left || pos>right) return 0;
if(left==right){
	// cout<<index<<" val "<<t[index].val<<endl;
	return t[index].val;
}
ll mid = left + (right-left)/2;
 
ll  a = query(index*2,left,mid,pos);
ll b = query(index*2+1,mid+1,right,pos);
return a+b;
 
 
 
}
 
int main(){
  #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
 
 
ll n , q;
cin >> n >> q;
vector<ll>v(n);
for(ll i=0; i<n; i++){
	cin>> v[i];
}
build(1,0,n-1,v);
 
while(q--){
	ll cnd ;
	cin>> cnd;
	if(cnd == 1){
		ll left , right , val;
		cin >> left >> right >> val;
		left-- , right--;
		update(1,0,n-1,left,right,val);
	}else{
ll k ;
cin >>k;
k--;
cout<<query(1,0,n-1,k)<<endl;
	}
 
 
 
}
 
 
 
 
 
	return 0;
}

