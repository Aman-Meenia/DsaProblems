#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;


//  USING BFS 
    vector<int> ans;
    bool topo_sort(vector<int> adj[],int n ){


vector<int> vis(n);
vector<int> indegree(n,0);

for(int i=0; i<n; i++){
for(auto it:adj[i]){
    indegree[it]+=1;
}
}

queue<int> q;

for(int i=0; i<n; i++){
    if(indegree[i]==0){
        // cout<<"' i. "<<i<<endl;
q.push(i);
    }
}

while(!q.empty()){

int node = q.front();
ans.push_back(node);
q.pop();

for(auto it:adj[node]){
    indegree[it]--;
    if(indegree[it]==0){
        q.push(it);
    }
}


}

if(ans.size()==n) return true;




return false;
}




int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif




}
