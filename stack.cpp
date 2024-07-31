#define ll long long 
#define mod 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& v) {
int n = v.size();
vector<ll> left(n,1);
vector<ll> right(n,1);
stack<pair<int,int>> st;
st.push({v[0],0});
for(int i=1; i<n; i++){
  int start = i;
  int end = i;
  while(!st.empty() && st.top().first>=v[i]){
start= st.top().second;
st.pop();
  }
  st.push({v[i],start});
  left[i]=end-start+1;
}




while(!st.empty()) st.pop();
st.push({v[n-1],n-1});
for(int i=n-2; i>=0; i--){
  int end = i;
  int start = i;
  while(!st.empty() && st.top().first>v[i]){
    end = st.top().second;

    st.pop();
  }
  st.push({v[i],end});
  right[i]=end-start+1;
}

ll ans =0;
for(int i=0; i<n; i++){
    int temp = ((left[i]*right[i])%mod*v[i]%mod)%mod;
    ans+=temp;
}


return ans%mod;

    }
};
