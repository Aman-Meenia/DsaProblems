#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct node{

int cnt;

node (){
	cnt =0;
}


};

node t[4*600100];
// merge

node merge(node a, node b){
	node ans;
	ans.cnt = a.cnt + b.cnt;
	// cout<<" Ans "<<ans.cnt<<endl;
	return ans;
}

#define mid (l+(r-l)/2)

// update 

void update(int index , int l , int r , int pos , int val){

if(l>pos || r<pos) return;

if(l==r){
t[index].cnt+=val;
	return;
}
update(2*index , l , mid , pos , val);
update(2*index+1 , mid+1 ,r , pos , val);
t[index] = merge(t[2*index],t[2*index+1]);



}

// get query

node get_query(int index , int l , int r , int lq , int rq){

if(lq>r || rq<l) return node();

if(lq<=l && rq>=r){
	return t[index];
}

node ans1 = get_query(2*index , l , mid , lq , rq);
node ans2 = get_query(2*index+1 , mid+1, r , lq , rq);
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
	cin >> v[i];
}

vector<vector<int>> q;

for(int i=0; i<k; i++){

char ch ;
cin >>ch;
int l , r;
cin >> l >> r ;


if(ch=='?'){
	// 1 Mean the number of employees whose salary is between a -> b
q.push_back({1,l,r});

}else{
		// 2 Mean  change the salary of employee l to r;
	q.push_back({2,l,r});
}

}

// coordinate compression

set<int>st;
unordered_map<int,int> mp;

for(auto it:v){
st.insert(it);
}

for(auto it:q){
// cout<<it[0]<<" it "<<it[1]<<"it "<<it[2]<<endl; 
if(it[0]==1){

st.insert(it[1]);
st.insert(it[2]);

}else{
	st.insert(it[2]);
}

}
int start = 0;
for(auto it:st){
mp[it]=start;
start++;
}

// for(auto it:mp){
// 	cout<<it.first<<" Second "<<it.second<<endl;
// }


// build Tree


for(int i=0; i<n; i++){
int pos = mp[v[i]];
// cout<<" POS "<<pos<<endl;
update(1,0,start,pos,1);
}





// answer query

// cout<<" CNT "<<start<<endl
for(auto it:q){

if(it[0]==1){
	// GET ANSWER FOR RANGE L TO R
	int l = it[1];
	int r = it[2];

l = mp[l];
r= mp[r];

node ans = get_query(1,0,start,l,r);

cout<<ans.cnt<<endl;


}else{

	// Update the value at index K to x
	int k = it[1];
	int x = it[2];
	k--;

	// Firstly decrease the count of the previous salary
int pos = mp[v[k]];
	update(1,0,start,pos,-1);

	// Increase the new salary count
	pos = mp[x];
update(1,0,start,pos,1);


	v[k]=x;




}





}





}