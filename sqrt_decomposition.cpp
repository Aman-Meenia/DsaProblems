#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;




vector<int>  build_sqrt(vector<int> & v){
int n= v.size();
int size = sqrt(n);
if(sqrt(n)>size)size++;
vector<int> dp(size);

for(int i=0; i<n; i++){
int min_val= INT_MAX;
    for(int j=i; j<min(n,i+size); j++){
min_val=min(min_val,v[j]);
    }

    dp[i/size]=min_val;
i+=size;
i--;
}


return dp;
}

int ans_queries(vector<int> &v,vector<int>& dp , int left , int right ){
int n = v.size();
 int size = sqrt(n);
if(sqrt(n)>size)size++;
int start_block = left/size;
int end_block = right/size;

int ans = INT_MAX;

//  if for left index complete block include 
if(start_block==end_block) {

    for(int i=left; i<=right; i++){
        ans=min(ans,v[i]);
    }
    return ans;
}

if(left%size==0){
ans = min(ans,dp[start_block]);
}else{
    //  if some portion of block is used in query
   
for(int i=start_block*size+left%size; i<start_block*size+size; i++){
ans = min(ans,v[i]);
}

}

for(int i=start_block+1; i<end_block; i++){
    ans=min(ans,dp[i]);
}


//  if for right index complete block include 

if(right%size==size-1){
ans = min(ans,dp[end_block]);
}else{

    for(int i=end_block*size; i<=(end_block*size+(right%size)); i++){
        ans = min(ans,v[i]);
    }


}



return ans;


}


//  UPDATE QUERY


void update_query(vector<int> & v ,vector<int> &dp, int index , int val){


int n = v.size();
 int size = sqrt(n);
if(sqrt(n)>size)size++;
int update_index = index/size +(index%size);
v[index]=val;


int block_no = index/size;
int ans = INT_MAX;
for(int i=block_no*size; i<(block_no*size+size); i++){
    // cout<<" i "<<i<<" ";
ans = min(ans,v[i]);
}
// cout<<endl;
dp[block_no]=ans;



// for(auto it:v)cout<<it<<" ";cout<<endl;
//     for(auto it:dp)cout<<it<<" ";cout<<endl;









}



int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

int n , q;
cin >>n >>q;
vector<int> v(n);
for(int i=0; i<n; i++){
    cin>>v[i];
}

vector<int> dp = build_sqrt(v);


   while(q--){
    int cnd ;
    cin >> cnd;
    if(cnd==1){
        int index , val;
        cin >> index >>val;
        index--;
        update_query(v,dp,index,val);
    }else{
    int left , right ;
    cin >> left >> right;
    left--,right--;
    cout<<ans_queries(v,dp,left,right)<<endl;
}
   }





    return 0;
}
