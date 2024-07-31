#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;

map<int,int> mp;
struct query{
    int l , r , index;
};
int  blocksize =3;
static int cmp(query &q1 , query &q2){

    // if((q1.l/(double)blocksize)<=(q2.l/(double)blocksize)){
    //       return q1.r<q2.r;
    // }
    return ((q1.l/(double)blocksize)<(q2.l/(double)blocksize));
}

//  TO REMOVE ELEMENT FROM WINDOW 
ll sum =0;
void remove(int index,vector<int> &v){
mp[v[index]]-=1;
}


//  TO ADD THE ELEMENT IN THE WINDOW 
 void add(int index , vector<int> &v){
    mp[v[index]]+=1;
 }

//  TO GET ANSWER

 ll get_answer(){
    ll ans =0;
for(auto it:mp){
    ll a= it.first;
    ll b = it.second;
 ans+=(b*b)*a;
}
    return ans;
 }



int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

int n , m;
cin >> n >> m;
vector<int> v(n);
for(int i=0; i<n; i++){
    cin >>v[i];
}

vector<query> q(m);
for(int i=0; i<m; i++){
int l , r;
cin >> l >>r;
// cout<<" l "<<l<<" r "<<r<<endl;
l-- , r--;
q[i].l=l;
q[i].r=r;
q[i].index=i;
}
blocksize = sqrt(n);
if(sqrt(n)>blocksize){
    blocksize+=1;
}
// for(auto it:mp){
//     ll a= it.first;
//     ll b = it.second;
// cout<<a<<" b is  "<<b<<endl;
//  // ans+=(b*b)*a;

// }
// cout<<" blocksize "<<blocksize<<endl;
// for(auto it:q){
//     cout<<it.l<<" r  "<<it.r<<" index  "<<it.index<<endl;
// }

sort(q.begin(),q.end(),cmp);

// for(auto it:v)cout<<it<<" ";cout<<endl;
int cur_l=0;
int cur_r=-1;
vector<int>ANS(m);
for(auto it:q){
    int left = it.l;
    int right = it.r;
    int index = it.index;
    // cout<<" left "<<left<< " right "<<right<<endl;
         while (cur_l > left) {
            cur_l--;
            add(cur_l,v);
        }
        while (cur_r < right) {
            cur_r++;
            add(cur_r,v);
        }
        while (cur_l < left) {
            remove(cur_l,v);
            cur_l++;
        }
        while (cur_r > right) {
            remove(cur_r,v);
            cur_r--;
        }

ANS[index]=get_answer();
}

for(auto it:ANS)cout<<it<<" "<<endl;







}
