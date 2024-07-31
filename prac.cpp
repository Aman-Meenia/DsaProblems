#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
 

 // static int cmp(vector<int>&a , vector<int>&b){
 //    return a[1]<b[1];
//  }
 

//  int room_with_maximum_meetings(vector<vector<int>> &v , int rooms){

// int dp[rooms];
// memset(dp,0,sizeof dp);


// int n = v.size();

// //  priority_queue for minimum room empty
// // priority_queue<int,vector<int> ,greater<int>>pq;

// priority_queue<pair<ll,ll>,vector<pair<ll,ll>> ,greater<pair<ll,ll>>>pq;
// priority_queue<pair<ll,ll>,vector<pair<ll,ll>> ,greater<pair<ll,ll>>>pq2;

// for(int i=0; i<rooms; i++)pq.push({i,0});
// int maxi=0;
// int start = 0;
// for(int i=0; i<v.size(); i++){
// ll temp = 0;


// while(!pq2.empty() && pq2.top().first<=v[i][0]){
//      pq.push({pq2.top().second,pq2.top().first});
// pq2.pop();
// }
// if(!pq2.empty()){

//     temp =pq2.top().first;
// }


// if(pq.empty()){
//     temp = max(pq2.top().first,(ll)v[i][0]);
// while(!pq2.empty() && pq2.top().first<=temp){
//     pq.push({pq2.top().second,pq2.top().first});
//     pq2.pop();
// }
// }

//     if(!pq.empty()){
//         int roomis = pq.top().first;
//         ll start = pq.top().second;
//         start=max(start,(ll)v[i][0]);
//         dp[roomis]+=1;

//         maxi=max(maxi,dp[roomis]);
//         pq.pop();
//         ll time_to_complete = v[i][1]-v[i][0];
//         pq2.push({start+time_to_complete,roomis});

//     }
// }
// // for(auto it:dp)cout<<it<<" ";cout<<endl;

// for(int i=0; i<rooms; i++){
// if(dp[i]==maxi) return i;
// }

// return -1;




//  }





int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1n;txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


// int n ;
// cin >>n;
//  vector<int> v(n);
//  for(int i=0; i<n; i++){
//     cin >>v[i];
//  }


// for(auto it:v)cout<<it<<" ";cout<<endl;



}
