#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;



struct node {

    int minSalary;
    int maxSalary;
    node(){
minSalary=0;
maxSalary=0;
    }
};

node t[4*200100];

// merge

node merge(node a , node b){

node ans;
ans.minSalary=min(a.minSalary,b.minSalary);
ans.maxSalary=max(a.maxSalary,b.maxSalary);
// cout<<ans.minSalary<<" ans "<<ans.maxSalary<<endl;

return ans;


}

// build

void build(int id , int l , int r , vector<int> &v){

if(l==r){
t[id].minSalary=v[l];
t[id].maxSalary=v[l];
    return ;
}

int mid = l+(r-l)/2;
build(2*id,l,mid,v);
build(2*id+1,mid+1,r,v);
t[id]=merge(t[2*id],t[2*id+1]);

}


// update 

void update(int id , int l , int r , int lq , int rq, int val){
    if(lq>r ||rq<l){
        return;
    }

    if(l>=lq && r<=rq){
        t[id].minSalary=val;
t[id].maxSalary=val;
        return;
    }

    int mid = l +(r-l)/2;

    update(2*id,l,mid,lq,rq,val);
    update(2*id+1,mid+1,r,lq,rq,val);
    t[id]=merge(t[2*id],t[2*id+1]);
}


// get ans
int get_query(int id , int l , int r ,  int minVal , int maxVal){


// cout<<t[id].minSalary <<" maxval "<<t[id].maxSalary<<endl;
if(t[id].minSalary>=minVal && t[id].maxSalary<=maxVal){

return r-l+1;

}else{
    if(l==r) return 0 ;
int mid = l + (r-l)/2;
int ans = 0;
// cout<<"l "<<l<<" r "<<r<<endl;
// || t[2*id].maxSalary>=minVal || t[2*id].maxSalary<=maxVal
    if(t[2*id].minSalary>=minVal && t[2*id].minSalary<=maxVal 
        || t[2*id].maxSalary>=minVal && t[2*id].minSalary<=maxVal
        ){
   ans+=  get_query(2*id,l,mid,minVal,maxVal);

    }
    // || t[2*id+1].maxSalary>=minVal || t[2*id+1].maxSalary<=maxVal
    if(t[2*id+1].minSalary>=minVal && t[2*id+1].minSalary<=maxVal 
        || t[2*id+1].maxSalary>=minVal  && t[2*id+1].minSalary<=maxVal){
   ans+= get_query(2*id+1,mid+1,r,minVal,maxVal);

    }
return ans;

}






}




int main(){
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


int n , k;
cin >>n >> k;
vector<int> v(n);
for(int i=0; i<n; i++){
    cin >>v[i];
}


build(1,0,n-1,v);


while(k--){

char ch;
cin>>ch;
int a , b;
    cin >> a >>b;
if(ch=='!'){
    a--;
    update(1,0,n-1,a,a,b);

}else{
    // cout<<" a "<<a<<" b "<<b<<endl;
cout<<get_query(1,0,n-1,a,b)<<endl;
}

}


}