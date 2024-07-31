#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;



struct node{

node * child[26];
bool last;

node(){
    for(int i=0; i<26; i++){
        child[i]=NULL;
    }
    last = false;
}


};



void insert(node *root , string s){

node *dummy = root;


for(int i=0; i<s.size(); i++){
    char ch= s[i];

if(dummy->child[ch-'a']==NULL){
node * n = new node();
dummy->child[ch-'a']=n;
}

dummy = dummy->child[ch-'a'];

}

dummy->last = true;


}



bool present(node * root , string &s){

node * dummy = root;
for(int i=0; i<s.size(); i++){
char ch= s[i];
if(dummy->child[ch-'a']==NULL){
    return false;
}
dummy = dummy->child[ch-'a'];

}

if(dummy->last==true) return true;

return false;

}


// diff_ways
 ll dp[5010];
ll diff_ways(string & s , int index, node * trie){
if(index>=s.size()) return 1;
node * dummy = trie;
int ans =0;
if(dp[index]!=-1) return dp[index];
for(int i=index; i<s.size(); i++){
    char ch = s[i];
    if(dummy==NULL){
     return 0;
}
dummy=dummy->child[ch-'a'];


if(dummy!=NULL && dummy->last==true){
int temp_ans= diff_ways(s,i+1,trie);
ans= (ans%mod+temp_ans%mod);
}




}
return dp[index]=ans;



}







int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

memset(dp,0,sizeof dp);
node * trie = new node();


string s;
cin >> s;


int k;
cin >> k;
vector<string> t(k);
while(k--){
    cin>>t[k];
}


for(auto it:t){
    insert(trie,it);
}


int n = s.size();
dp[n]=1;


for(int index=n-1; index>=0; index--){
node *dummy = trie;
int temp_ans = 0;
string tt;
for(int i=index; i<n; i++){
    tt.push_back(s[i]);
     char ch = s[i];
    if(dummy==NULL){
    break;
}

dummy=dummy->child[ch-'a'];


if(dummy!=NULL && dummy->last==true){
 temp_ans=temp_ans%mod + dp[i+1]%mod;
}

}
dp[index]=temp_ans%mod;

}

cout<<dp[0]<<endl;






}