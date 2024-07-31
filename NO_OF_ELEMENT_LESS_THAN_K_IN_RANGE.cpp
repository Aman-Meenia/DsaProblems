
// Given an array of size n and we have m different queries
// query -> ( L , R , K )
// For every query we have to count the number of element which are less or equal to k in
// the range (l->r).
// k-> can be different for every query




#include<bits/stdc++.h>
#define ll long long
using namespace std;


#define mid (l+(r-l)/2)



struct node{
int cnt ;
	node(){
cnt = 0;
	}
};

// Delcare array
node t[4*100100];

// merge

node merge(node a , node b){
	node ans;

ans.cnt = a.cnt+b.cnt;

	return ans;
}

// build

// NO Need


// update 

void update(int index , int l , int r , int lq , int rq){


if(lq>r || rq<l){
	return ;
}

if(lq<=l && rq>=r){

t[index].cnt = 1;
	return ;
}

update(2*index , l , mid , lq , rq);
update(2*index+1, mid+1, r , lq , rq);

t[index] = merge(t[2*index],t[2*index+1]);

}

// get query


node ans_query(int index , int l , int r , int lq , int rq){

	if(lq>r || rq<l) return node();

if(lq<=l && rq>=r){
return t[index];
}

node ans1= ans_query(2*index , l , mid , lq , rq);
node ans2 = ans_query(2*index+1 , mid+1 , r , lq , rq);

return merge(ans1, ans2);

}




#undef mid

static int cmp(vector<int> & a , vector<int> & b){
	return a[2]<b[2];
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


vector<vector<int>> v;

for(int i=0; i<n; i++){
	int val;
	cin >> val;
v.push_back({val,i});
}


vector<vector<int>> q(k,vector<int>(4,0));

for(int i=0; i<k; i++){
cin >> q[i][0] >> q[i][1] >> q[i][2];
q[i][3]=i;
}


sort(q.begin(),q.end(),cmp);

sort(v.begin(),v.end());

// for(auto it:v){
// 	cout<<it[0]<<" # "<<it[1]<<endl;
// }


vector<int> ANS(k);

int index = 0;
for(int i=0; i<q.size(); i++){
int l = q[i][0];
int r = q[i][1];
int k_val = q[i][2];
l-- , r--;


while(index<n && v[index][0]<=k_val){
	int idx = v[index][1];
update(1,0,n-1,idx,idx);

index++;
}


// get query
node ans = ans_query(1,0,n-1,l,r);
ANS[q[i][3]]=ans.cnt;

}


for(auto it:ANS){
	cout<<it<<" ";
}cout<<endl;





}