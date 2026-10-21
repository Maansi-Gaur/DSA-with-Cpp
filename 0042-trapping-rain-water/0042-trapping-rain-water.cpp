class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int watertrap=0;
        int l=0; 
        int maxleft=0;
        int maxright=0;
        int r= n-1;
        while(l<=r){
           if(height[l]<=height[r]){
            if(maxleft<height[l]){
                maxleft=  height[l];
                
            }
            watertrap+=(maxleft-height[l]);
            l++;
           }else{
            if(maxright<height[r]){
                maxright= height[r];
               
            }
            watertrap+=(maxright-height[r]);
            r--;
           }
        }
        return watertrap;
    }
};