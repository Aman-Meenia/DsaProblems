#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
 

int vis[510];


bool bipartite(vector<int>  adj[] , int root){
// cout<<root<<endl;
  for(auto it:adj[root]){
if(vis[it]==-1){
vis[it]=1-vis[root];
if(!bipartite(adj,it)) return false;
}else{
  // cout<<" it "<<it<<" root " <<root<<endl;
  if(vis[it]==vis[root]) {
    return false;
  }

}
  }
return true;
}


int max_length_graph(vector<int> adj[] , int root,int n){
  vector<int> cnt(n,-1);
  int cnt_level = 1;
  queue<int> q;
  q.push(root);
cnt[root]=0;
  while(!q.empty()){
int size = q.size();

for(int i=0; i<size; i++){
int node=q.front();
q.pop();

for(auto it:adj[node]){
if(cnt[it]==-1){
  cnt[it]=cnt_level;
  q.push(it);
}else if(abs(cnt[it]-cnt[node])>1) return -1;
}


}
cnt_level++;

  }
  return cnt_level-1;
}



int component_check(vector<int> adj[], vector<int> &v ,int n ){

// cout<<v[0]<<endl;
vis[v[0]]=1;
if(!bipartite(adj,v[0])) return INT_MAX;
int ans =0;
// for(auto it:v)cout<<it<<" ";cout<<endl;
for(int i=0; i<v.size(); i++){

ans = max(ans,max_length_graph(adj,v[i],n));

}


return ans;


}








vector<vector<int>> components;
vector<int> temp;
void components_fun(vector<int> adj[],vector<int> &dp , int root){
temp.push_back(root);
for(auto it:adj[root]){
  if(dp[it]==-1){
    dp[it]=1;
    components_fun(adj,dp,it);
  }
  
}

}



int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

int n = 92;
int size ;
cin >> size;
  vector<vector<int>> v;
for(int i=0; i<n; i++) {
  int a , b;
  cin >> a >> b;
  v.push_back({a,b});
}





vector<int> adj[n+1];
      for(int i=0; i<size; i++){
        int a= v[i][0];
        int b = v[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
      }


vector<int> dp(n+1,-1);
for(int i=1; i<=n; i++){
  temp.clear();
  if(dp[i]==-1){
    dp[i]=1;
components_fun(adj,dp,i);
}
if(temp.size()>0)
components.push_back(temp);

}
int ans = 0;
memset(vis,-1,sizeof vis);
for(auto it:components){
int tt = component_check(adj,it,n+1);
if(tt==INT_MAX){
  cout<<" -1"<<endl;
  return 0;
  //  check for all the components
}else{
  ans+=tt;
}

}
cout<<" ANS "<<ans<<endl;






}
