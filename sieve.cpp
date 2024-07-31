#include<bits/stdc++.h>
#define ll long long

using namespace std;




vector<int> sieve_fun(vector<int> &v  ){
int n = v.size();
int maxi = INT_MIN;
for(auto it:v){
maxi=max(maxi,it);
}

int dp[maxi+1];
memset(dp,0,sizeof dp);



for(int i=0; i<n; i++){
dp[v[i]]+=1;
}
int cnt = 0;
vector<int> ans(maxi+ 1);
cout<<" maxi. "<<maxi<<endl;
for(int i=1; i<=maxi; i++){
 cnt = 0;
	for(int j=i; j<=maxi; j+=i){
		
	cnt++;
		ans[i]+=dp[j];
	}
	cout<<" I. "<<i<<" cnt "<<cnt<<endl;
}

// for(auto it:ans)cout<<it<<" ";cout<<endl;
return ans;
}


    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }







int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


int n;
cin >>n;
vector<int> v(n);
for(int i=0; i<n; i++){
	cin >>v[i];
}

sieve_fun(v);



// for(int i=1; i<=10000; i++){
// 	cout<<i<<" ";
// }cout<<endl;



}