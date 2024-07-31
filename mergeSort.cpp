class Solution {
public:

    void merge(vector<int> &v, int low, int mid, int high){
        int i=low;
        int j=mid+1;
      
        vector<int> ans;
 
        while(i<=mid && j<=high){
            if(v[i]<=v[j]){
           ans.push_back(v[i]);
                i++;
            
            }else{
           ans.push_back(v[j]);
                j++;
     
            }
        }
        while(i<=mid){
                    ans.push_back(v[i]);
               i++;
        }
           while(j<=high){
                      ans.push_back(v[j]);
               j++;  
        }
        int k=0;
        for(int i=low; i<=high; i++){
            v[i]=ans[k];
            k++;
        }
        
    }
    
    
  void  mergesort(vector<int> &v,int low, int high){
      if(low<high){
          int mid=(low+high)/2;
          mergesort(v,low,mid);
          mergesort(v,mid+1,high);
          merge(v,low,mid,high);
      }
      
  }
    vector<int> sortArray(vector<int>& nums) {

        mergesort(nums,0,nums.size()-1);
       return nums; 
    }
};
