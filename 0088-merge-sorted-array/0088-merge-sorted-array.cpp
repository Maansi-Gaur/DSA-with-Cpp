class Solution {
public:
    void swapifgreator(vector<int>& nums1, int idx1, vector<int>& nums2, int idx2){
         if(nums1[idx1]>nums2[idx2]){
            swap(nums1[idx1],nums2[idx2]);
        }
        return;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int len = m+n;
       int gap= (len/2)+(len%2);
      
       while(gap>0){
         int i=0;
         int j= i+gap;
         while(j<len){
            if(i<m&& j>=m) swapifgreator(nums1, i, nums2, j-m);
            else if(i<m&& j<m) swapifgreator(nums1, i, nums1, j);
            else swapifgreator(nums2, i-m, nums2, j-m);
             i++; j++;
         }
            if(gap == 1)
                break;
            
            gap= (gap/2)+(gap%2);
       }
           
       for(int i=0; i<n; i++){
          nums1[i+m]= nums2[i];
       }
       return;
    }
};