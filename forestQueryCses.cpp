#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


int main(){
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif



int n , k;
cin >> n >> k;

vector<vector<char>> v(n,vector<char>(n));

for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        cin>>v[i][j];
    }
}
// for(auto it:v){
//     for(auto a:it){
//         cout<<a<<" ";
//     }cout<<endl;
// }

vector<vector<int>>left(n,vector<int>(n));

for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        int val = 0;
        if(v[i][j]=='*') val= 1;

        left[i][j]=val+(j>0?left[i][j-1]:0);
    }
}

while(k--){
int a , b , c , d;
cin >> a >> b >> c >> d;
a-- , b-- , c-- , d--;
int ans = 0;
for(int x=a; x<=c; x++){

ans+= left[x][d]-(b>0?left[x][b-1]:0);

}
cout<<ans<<endl;



}















}