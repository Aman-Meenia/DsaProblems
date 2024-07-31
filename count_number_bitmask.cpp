#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;


ll dp[20][12][2][2];

ll count_number_between(string & s , int index , int pre , int cnd, bool zero){

if(index==s.size()){
return 1;
}
ll ans =0;

if(dp[index][pre+1][cnd][zero]!=-1) return dp[index][pre+1][cnd][zero];

// if pre = -1 we can place any value upto n 
if(pre==-1){
int last = s[index]-'0';
for(int i=0; i<=last; i++){
if(i==0){
   ans= ans+count_number_between(s,index+1,i,true,true);
}else if(i==last){
ans = ans+count_number_between(s,index+1,i,false,zero);
}else{
    ans = ans+count_number_between(s,index+1,i,true,zero);
}

}

}else{

if(cnd==true){

    for(int i=0; i<=9; i++){

if(i==0 && zero==true){
    ans = ans+count_number_between(s,index+1,i,true,true);
    }else{
        if(i==pre) continue;
        ans = ans+count_number_between(s,index+1,i,true,false);
    }
}


}else if(cnd==false){
int last = s[index]-'0';
    for(int i=0; i<=last; i++){
if(i==last){
            if(i==pre) continue;
    ans = ans+count_number_between(s,index+1,i,false,false);
    }else{
         if(i==pre) continue;
        ans = ans+count_number_between(s,index+1,i,true,false);
    }
    }



}



}




return dp[index][pre+1][cnd][zero]=ans;



}
 
int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
 

ll a , b;
cin >> a>> b;
a-=1;
string s = to_string(a);
memset(dp,-1,sizeof dp);
ll ans1 = count_number_between(s,0,-1,false,false);
string s1 = to_string(b);
memset(dp,-1,sizeof dp);
ll ans2 = count_number_between(s1,0,-1,false,false);
cout<<ans2-ans1<<endl;


}

