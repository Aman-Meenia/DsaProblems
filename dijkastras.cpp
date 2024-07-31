#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;


    vector<int> dijkastras1(vector<pair<int,int>> adj[] , int root , int n ){

vector<int> dp(n,INT_MAX);

priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;

dp[root]=0;
pq.push({0,root});
while(!pq.empty()){
int node = pq.top().second;
int dis = pq.top().first;
pq.pop();
if(dis>dp[node]) continue;



for(auto it:adj[node]){
int t = it.first;
int t_dis = it.second;
t_dis +=dis;
if(t_dis<dp[t]){
    dp[t]=t_dis;
    pq.push({t_dis,t});

}
}


}


return dp;
}





    vector<int> dijkastras(vector<vector<int>> adj[] , int root , int n ){

vector<int> dp(n,INT_MAX);

priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;

dp[root]=0;
pq.push({0,root});
while(!pq.empty()){
int node = pq.top().second;
int dis = pq.top().first;
pq.pop();
if(dis>dp[node]) continue;



for(auto it:adj[node]){
int t = it[0];
int t_dis = it[1];
t_dis +=dis;
if(t_dis<dp[t]){
    dp[t]=t_dis;
    pq.push({t_dis,t});

}
}


}


return dp;
}







int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif




}
