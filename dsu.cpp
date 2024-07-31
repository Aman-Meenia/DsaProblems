#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
#define  N 1000000


int Parent[N];
int Rank[N];
int setSize[N];
int maxSetSize=1;
int differentSets;

void make_set(int n ){
    for(int i=0; i<n; i++){
        Parent[i]=i;
        Rank[i]=0;
        setSize[i]=1;

    }
}


int find_parent(int node){
    if(node==Parent[node]){
return node;
    }
    return Parent[node]=find_parent(Parent[node]);// path compressin
}


void union_find(int u , int v){
    u = find_parent(u);
    v = find_parent(v);
    // if same parent return 
    if(u==v) return;
   if(Rank[u]<Rank[v]) swap(u,v); 
  Parent[v] = u;
if(Rank[u]==Rank[v]) Rank[u]+=1;
setSize[u]+=setSize[v];
maxSetSize=max(maxSetSize,setSize[u]);
differentSets--;

}


int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

int n ;
cin >> n;
differentSets = n;
int m ;
cin >> m;

vector<vector<int>> v;
for(int i=0; i<m; i++){
  int a , b;
  cin >> a >> b;
  v.push_back({a,b});
}

make_set(n);

for(auto it:v){
  int a = it[0];
  int b = it[1];
a--;
b--;
  union_find(a,b);
  cout<<differentSets<<" "<<maxSetSize<<endl;
}



}
