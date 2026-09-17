class Solution {
    public int[] applyOperations(int[] nums) {
        int sz= nums.length;
        for(int i=0;i<sz-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int zeros=0,idx=0;
        int []ans=new int[sz];
        for(int i=0;i<sz;i++){
            if(nums[i]!=0)
              ans[idx++]=nums[i];
            else
                zeros++;
        }
        for(int i=0;i<zeros;i++){
            ans[idx++]=0;
        }
        return ans;
    }
}
