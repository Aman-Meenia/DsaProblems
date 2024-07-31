#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


struct trie{

    trie * children[26];
    int last;

    trie(){
        last = 0;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
    }
};


// insert in trie 
void insert(string & s , trie *root){
int n = s.size();
trie *currentNode = root;

for(int i=0; i<n; i++){
char ch = s[i];

if(currentNode->children[ch-'a']==NULL){
trie * node = new trie();
currentNode->children[ch-'a']=node;
}

currentNode=currentNode->children[ch-'a'];

}
currentNode->last+=1;

}

// check in trie

// bool present(string & s , trie *root){
//     int n = s.size();
//     trie *currentNode = root;

//     for(int i=0; i<n; i++){
//         char ch = s[i];
  
//   if(currentNode->children[ch-'a']==NULL) return false;
//   currentNode=currentNode->children[ch-'a'];


//     }
//     if(currentNode->last==true)
//     return true;
// return false;
// }



int dp[5010][5010];
ll dp2[5010];




ll fun(string & s , int index){
if(index>=s.size()){
    return 1;
}

ll ans = 0;
if(dp2[index]!=-1){
    return dp2[index];
}

for(int i=index; i<s.size(); i++){
  if(dp[index][i]!=0){

ans=ans%mod+fun(s,i+1)%mod;

  }

}

return dp2[index]=ans%mod;


}












int main(){
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif



trie * root = new trie();
string s ;
cin >>s;
int n = s.size();

int m ;
cin >>m;
vector<string> t(m);
for(int i=0; i<m; i++){
    cin >>t[i];
}
for(auto it:t){
    insert(it,root);
}


memset(dp,0,sizeof dp);
memset(dp2,-1,sizeof dp2);
for(int i=0; i<n; i++){
    trie *currentNode = root;
for(int j=i; j<n; j++){
    char ch = s[j];
  if(currentNode->children[ch-'a']==NULL) break;
  currentNode=currentNode->children[ch-'a'];
dp[i][j]=currentNode->last;
}

}


cout<<fun(s,0)<<endl;








}
