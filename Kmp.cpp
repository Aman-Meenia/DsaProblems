#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
#define mod 1000000007
using namespace std;



// vector<int> Kmp_fun(string & s){
//   int n = s.size();

// int j = 0;
// vector<int> v(n,0);
// // cout<<n<<endl;
// for(int i=1; i<n; i++){
//   int j = v[i-1];
// while(j>0 &&s[j]!=s[i] ){
// j=v[j-1];
// }

// if(s[i]==s[j]){
//   j++;
// }
//  v[i]=j;


// }

// return v;


// }
vector<int> Kmp_fun(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {https://music.youtube.com/watch?v=ulcv4ExCaW0&list=RDAMVMulcv4ExCaW0
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


vector<int> give_start_index(vector<int> v, string &s , string & t){



int n = s.size();
int m = t.size();


int i =0;
int j =0;
vector<int> ans;
for(auto it:v) cout<<it<<" ";cout<<endl;
while(i<n){
  if(s[i]==t[j]){
    j++;
    i++;
  }
cout<<" j "<<j<<endl;
  if(j==m){
    // cout<<" j "<<j<<" i "<<i<<endl;
    ans.push_back(i-m);
     j=v[j-1];
   }else if(s[i]!=t[j]){
    if(j==0) i++;
    else j = v[j-1];
   }




}

return ans;




}






int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


string s , a , b;
cin >> s >> a >> b;
int k ;
cin >>k;



vector<int> temp = Kmp_fun(a);
vector<int> v1 = give_start_index(temp,s,a);
temp = Kmp_fun(b);
vector<int> v2 = give_start_index(temp,s,b);
int n = v1.size();
int m = v2.size();

vector<int> ans;
map<int,int> mp;
for(int i=0; i<m; i++){
  mp[-v2[i]]=i;
}
vector<int> v;
  for(int i=0; i<m; i++) v.push_back(-v2[i]);
cout<<v1.size()<<endl;



for(int i=0; i<v1.size(); i++){
int val = v1[i];
int start = val-k;
int end = val+k;
auto it1 = lower_bound(v2.begin(), v2.end(),start);
if(*it1>end) continue;
ans.push_back(val);

}

for(auto it:ans)cout<<it<<" ";cout<<endl;


}
