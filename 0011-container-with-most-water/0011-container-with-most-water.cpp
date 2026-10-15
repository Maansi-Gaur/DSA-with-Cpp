class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size()-1;
        int l=0;
        int r= n;
        int maxwater= INT_MIN;
        while(l<r){
         int w= r-l;
         int h= min(height[l], height[r]);
         int curr= w*h;
         maxwater= max(maxwater,curr);
         height[l]<height[r]? l++:r--;
        }
        return maxwater;
    }
};