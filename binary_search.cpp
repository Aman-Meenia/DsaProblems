#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;

int binary_search(vector<int> & v ,int l , int h , int target){

 while(l<=h){
     int mid = l + (h-l)/2;
if(v[mid]==target){
  return mid;
}else if (v[mid]>target){
  h=mid-1;
}else {
  l=mid+1;
}
 }

return -1;
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
for(int i=0; i<n; i++){
  cin >> v[i];
}


int target = 8;
cout<<binary_search(v,0,n-1,target)<<endl;

}
