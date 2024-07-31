#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;


void generate_subset(vector<int> & v,int n){

int bit_mask = (1<<n);
cout<<bit_mask<<endl;

for(int mask = 0; mask<bit_mask; mask++){
vector<int> temp;
    for(int i=0; i<n; i++){
if((mask&(1<<i))!=0){
    temp.push_back(v[i]);
}
    }
    for(auto it:temp)cout<<it<<" ";cout<<endl;

}


}

ll gcd(ll a , ll b){
    if(b==0) return a;
    return (b,a%b);
}


ll lcm(ll a , ll b){
    return (a*b)/gcd(a,b);
}






int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


    int n ;
    cin >>n;

vector<int> v(n);
for(int i=0; i<n; i++){
    v[i]=i+1;
}

generate_subset(v,n);
cout<<pow(2,15)<<endl;




}
