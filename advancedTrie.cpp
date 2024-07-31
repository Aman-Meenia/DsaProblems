#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
 

struct trie{
	trie * children[26];
	int end;
	trie(){
		end = 0;

		for(int i=0; i<26; i++){
children[i]=NULL;
		}
	}




};




void insert(string &s , trie *root){
int n = s.size();
trie *currentnode = root;
for(int i=0; i<n; i++){
char ch = s[i]-'a';
if(currentnode->children[ch]==NULL){
	trie * n = new trie();
	currentnode->children[ch]=n;
}
currentnode=currentnode->children[ch];

}

currentnode->end+=1;

}

bool isPalindrome(string & s){

int low = 0; 
int high = s.size()-1;

while(low<=high)
{

if(s[low]!=s[high]){
	return false;
}
low++;
high--;
}

return true;
}







int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


ll n ;
cin >> n;
vector<string> s(n);

for(int i=0; i<n; i++){
	cin>> s[i];
}

trie * root = new trie();
for(auto it:s){
	insert(it,root);
}
cout<<fixed<<pow(2,60)-1<<endl;


}
