#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;



string  buildString(string & s ){

int n = s.size();
string t;
for(int i=0; i<n; i++){
t.push_back('#');
t.push_back(s[i]);
}
t.push_back('#');
// cout<<t<<endl;
    return t;
}


vector<int> p;

void manacher(string & s){
int n = s.size();
p.assign(n,1);
int l =1;
int r=1;

for(int i=1; i<n; i++){

cout<<" i "<<i<<" l "<<l <<" r "<<r<<endl;
    p[i]=max(0,min(r-i,p[l+r-i]));

    while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]]){
        p[i]++;
    }

    if(i+p[i]>r){
        l=i-p[i];
        r=i+p[i];
    }

}


for(auto it:s){
    cout<<it<<" ";
}cout<<endl;

for(auto it:p){
    cout<<it<<" ";
}cout<<endl;





}


int main(){
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


string s;
cin >>s;

s = buildString(s);
manacher(s);

int cnt = 0;

int index = -1;
for(int i=0; i<p.size(); i++){
    if(p[i]>cnt){
    cnt = max(cnt,p[i]);
    index = i;
}
}

// cout<<index<<endl;

// string ans;

// if(s[index]=='#'){
// int left=index;
// int right=index;

// while(ans.size()<cnt/2){
//     left--;
//     ans.push_back(s[left]);
//     left--;

// }
// string temp = ans;
// reverse(temp.begin(),temp.end());
// cout<<temp+ans<<endl;




// }else{


//     int left = index;

//     while(ans.size()<cnt/2){
// ans.push_back(s[left]);
// left-=2;
//     }
// string t = ans;
// reverse(t.begin(),t.end());
// t.pop_back();
// cout<<t+ans<<endl;




// }




// cout<<cnt-1<<endl;






}
