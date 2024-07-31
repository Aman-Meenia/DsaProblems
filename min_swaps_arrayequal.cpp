#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;


int min_swaps(vector<int> & v , vector<int> & t ){
  int n = v.size();
  unordered_map<int,int> mp;
unordered_map<int,int> mp2;
  for(auto it :v){
    mp[it]+=1;
  }
for(int i=0; i<n; i++){
  mp2[t[i]]=i;
}
int ans = 0;
for(int i=0; i<n;i++){
while(v[i]!=t[i]){
int val_index = mp2[v[i]];
swap(v[i],v[val_index]);
ans++;
}

}
return ans;
}

int main (){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

  int n; 
  cin >> n;
  vector<int> v(n);
  vector<int> t(n);
  for(int i=0; i<n; i++) cin>>v[i];
  for(int i=0; i<n; i++) cin>>t[i];

    for(auto it:v){
      cout<<it<<" ";
    }cout<<endl;
    for(auto it:t)cout<<it<<" ";cout<<endl;

      cout<<min_swaps(v,t)<<endl;
  return 0;
}
