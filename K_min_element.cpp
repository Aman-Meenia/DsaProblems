#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;



ll get_k_min_element_sum(vector<int> & v ,int low , int high ,  int k ,int size){
  int n = v.size();
ll ans =LLONG_MAX;
multiset<int> st1;
multiset<int> st2;
ll sum =0;

while(high<n){



//  insert in heap1 and if size greater than k the insert its last element in heap2
  st1.insert(v[high]);
  sum+=v[high];
if(st1.size()>k){
int val = *st1.rbegin();
sum-=val;
st1.erase(st1.find(val));
st2.insert(val);
}


//  if size of heap equal to the size of require window (erase one element and insert one element )
  if(high-low==size){
ans = min(ans,sum);
    int val = v[low];
    // if present in the first heap 
  if(st1.find(val)!=st1.end()){

sum-=val;
auto it = st1.find(val);
st1.erase(it);


// we check  because if the size of window equal to the size of k the we do not have any extra element in the heap 2 
if(!st2.empty()){
  val = *st2.begin();
st2.erase(st2.find(val));
st1.insert(val);
sum+=val;
}

}
else{
// if present in second heap 
    auto it = st2.find(val);
    st2.erase(st2.find(val));

  }

    low++;


}


high++;


}
  return ans;
}




int  main( ){
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
  cin>>v[i];
}

int k , size;
cin >> k >> size;
k-=1;
cout<<v[0]+get_k_min_element_sum(v,1,1,k,size);




}
