class Solution {
       public int maxArea(int[] height) {
        int r=height.length-1;
        int l=0;
        int ans=0;
        while(l<r){
            int mnHeight=height[l];
            int width=r-l;
            if(height[l]<height[r]) {
                l++;
            }
            else {
                mnHeight=height[r];
                r--;
            }
            int area=  mnHeight *width;
            ans=Math.max(ans,area);
        }
        return ans;
    }
}
