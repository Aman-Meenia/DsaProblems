#include<bits/stdc++.h>
#define ll long long
using namespace std;





int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


int n ;
cin >> n;


vector<int> v(n);

for(int i=0; i<n; i++){
	cin >>v[i];
}


vector<int> ans;
ans.push_back(v[0]);
for(int i=1; i<n; i++){

if(v[i]>ans.back()){
	ans.push_back(v[i]);
}else{

auto it = lower_bound(ans.begin(),ans.end(),v[i])-ans.begin();

ans[it]=v[i];

}




}

cout<<ans.size()<<endl;



}