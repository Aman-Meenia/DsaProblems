#include<bits/stdc++.h>
#define ll long long
using namespace std;





struct node {
int maxi;
node(){
    maxi = 0;
}

};


node t[4*100000];


node merge(node a , node b){

    node ans;
    ans.maxi= max(a.maxi , b.maxi);
    return ans;
}

void update(int index , int l , int r , int lq , int rq , int val){

if(lq>r || rq<l){
    return ;
}

if(lq<=l && rq>=r){
t[index].maxi = max(val,t[index].maxi);
    return ;
}

int mid = l +(r-l)/2;


update(2*index , l , mid , lq , rq , val);
update(2*index+1 , mid+1 , r , lq ,rq , val);

t[index]= merge(t[2*index],t[2*index+1]);


}



// get ans 

node get_ans(int index , int l  , int r , int lq , int rq){

if(lq>r || rq<l){
    return node();
}

if(lq<=l && rq>=r){

    return t[index];
}

int mid = l +(r-l)/2;

node ans1 = get_ans(2*index , l , mid , lq , rq);
node ans2 = get_ans(2*index+1 , mid+1, r , lq , rq);

return merge(ans1, ans2);


}


int main(){


#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

int n;
cin >> n;



vector<int> v(n);
int max_val = 0;
for(int i=0; i<n; i++){
    cin >> v[i];
    max_val = max(max_val,v[i]);
}
int Ans = 0;

int k =5;

for(int i=0; i<n; i++){
    int start = v[i]-k;
    start = max(start,0);
    int end = v[i]-1;
node ans = get_ans(1,0,max_val,start,end);
Ans = max(Ans,ans.maxi+1);

update(1,0,max_val,v[i],v[i],ans.maxi+1);


}

cout<<Ans<<endl;





}