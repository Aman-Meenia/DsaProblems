#include<bits/stdc++.h>
#define ll long long 
using namespace std;


int n , k;


vector<int> v;

bool check(int mid){
int cnt = 1;
ll pre = v[0];
for(int i=1; i<n; i++){
if(v[i]-pre>mid){
cnt++;
pre = v[i];
}
if(cnt>=k){
	return true;
}
}



return false;
}





void fun(){



cin >> n >> k;
v.resize(n);
for(int i=0; i<n; i++){
	cin >>v[i];
}

sort(v.begin(),v.end());

int low = 0;
int high = INT_MAX;

while(low<=high){
	int mid = low + (high-low)/2;

	if(check(mid)){
low = mid+1;
	}else{
high = mid-1;
	}
}



cout<<low<<endl;


}

 
 

int main(){
 
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

int t;
cin >>t;
while(t--){
	fun();
}



 

	return 0;
}
