#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;



struct node
{
    ll sum;
    ll lazy_start;
    ll lazy_diff;

    node(){
        sum = 0;
        lazy_start=0;
        lazy_diff=0;
    }
    
};


node t[4*200100];

// merge logic 

node merge(node a , node b){
    node ans;
    ans.sum = a.sum+b.sum;

return ans;
}

// build logic
void build(int id , int l , int r , vector<int>& v){

if(l==r){
 t[id].sum=v[l];
 t[id].lazy_start=0;
 t[id].lazy_diff=0;
    return ;
}
int mid = l +(r-l)/2;

build(2*id,l,mid,v);
build(2*id+1,mid+1,r,v);
t[id] = merge(t[2*id],t[2*id+1]);

}


// get AP sum

ll getApSum(int start , int n , int diff){
ll sum = ((ll)n * (2 * (ll)start + (n - 1) * (ll)diff)) / 2;

return sum;

}

ll getNth(int start , int n , int diff){
    return start+(n-1)*diff;
}

//  lazy logic

void lazy_push(int id , int l , int r){
    if(t[id].lazy_start==0) return;

if(l!=r){


    int mid = l + (r-l)/2;

    t[2*id].lazy_start+=t[id].lazy_start;
    t[2*id].lazy_diff+=t[id].lazy_diff;

    int midindex = mid+1-(l-1);
ll sum = getNth(t[id].lazy_start,midindex,t[id].lazy_diff);
    t[2*id+1].lazy_start+=sum;
    t[2*id+1].lazy_diff+=t[id].lazy_diff;


}
// apply at current state
int n = r - l +1;
ll sum = getApSum(t[id].lazy_start,n,t[id].lazy_diff);
t[id].sum+=sum;
t[id].lazy_start=0;
t[id].lazy_diff=0;


}



// update

void update(int id , int l , int r , int lq , int rq , int start , int diff){
lazy_push(id,l,r);
if(lq>r||rq<l){
    return ;
}
if(l>=lq && r<=rq){

 t[id].lazy_start+=l-lq+1;
 t[id].lazy_diff+=diff;

 lazy_push(id,l,r);
    return ;
}

int mid = l + (r-l)/2;
update(2*id,l,mid,lq,rq,start,diff);
update(2*id+1,mid+1,r,lq,rq,start,diff);
t[id]=merge(t[2*id],t[2*id+1]);

}

// get answer

node get_query(int id , int l , int r , int lq , int rq){
    lazy_push(id,l,r);
if(lq>r||rq<l) return node();

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


int n , k ;
cin >> n >> k;
vector<int> v(n);

for(int i=0; i<n; i++){
    cin >>v[i];
}

build(1,0,n-1,v);


while(k--){

    int a , b , c;
    cin >> a >> b >> c;

b--,c--;
    if(a==1){

int start = 1;
int diff = 1;

update(1,0,n-1,b,c,start,diff);

    }else{

node ans = get_query(1,0,n-1,b,c);
cout<<ans.sum<<endl; 

    }




}





}
